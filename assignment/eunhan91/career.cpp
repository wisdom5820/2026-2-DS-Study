/*
1. 사용한 AI: GPT-6.2 Astra (High)
2. 과제에 활용한 부분: 식별자 이름을 정하고 비교 연산자의 우선순위 판단 로직을 수정하는 데 활용했습니다.
3. 도움이 필요했던 부분: 변수와 함수의 역할이 이름에 드러나도록 식별자를 고르는 데 도움을 받았습니다.
   또한 대기실이 비었을 때 다음 도착자를 선택하는 조건과 상담 후 시간을 갱신하는 과정에서 생긴 오류를 함께 점검했습니다.
4. AI가 제시한 코드에서 개선한 부분: 일부 식별자는 기존 이름을 유지했습니다.
   비교 연산자에서는 두 방문객이 아직 도착하지 않았는지를 각각 한 번만 계산한 뒤,
   그 결과를 변수에 저장해 이후 우선순위 판단에 사용했습니다.
*/
#include <bits/stdc++.h>

using namespace std;

int current_minute = 30;

struct Guest
{
    int arrival_time;
    int member_id;
    int remaining_minutes;

    bool operator < (const Guest & rhs)const{
        bool not_arrived=current_minute < arrival_time;
        bool rhs_not_arrived=current_minute < rhs.arrival_time;

        if(not_arrived != rhs_not_arrived) return not_arrived;
        if(not_arrived && rhs_not_arrived) return arrival_time > rhs.arrival_time;

        int other_remaining_minutes=rhs.remaining_minutes;

        if(other_remaining_minutes != remaining_minutes) return remaining_minutes < other_remaining_minutes;

        return arrival_time > rhs.arrival_time; //tie break
    }//end of overloading
};//end of Guest

class WaitingQueue:public priority_queue<Guest>{
    using Base=priority_queue<Guest>;

    public:
        const Guest & top(){
            ranges::make_heap(c, comp);

            return Base::top();
        }//end of top

        void push(Guest guest){
            ranges::make_heap(c, comp);

            Base::push(guest);
        }//end of push
        //현재 흐름상 pop은 오버로딩할 필요 없다.
};//end of WaitingQueue

WaitingQueue read_waiting_queue(){
    int guest_count;
    WaitingQueue waiting_queue;

    cin>>guest_count;

    while(guest_count--){
        int arrival_time, member_id, requested_minutes;

        cin>>arrival_time>>member_id>>requested_minutes;

        waiting_queue.emplace(arrival_time, member_id, requested_minutes);
    }//end of loop

    return waiting_queue;
}//end of read_waiting_queue

vector<int> compute_departure_order(WaitingQueue & waiting_queue) {
    
    vector<int> departure_order;

    while(!waiting_queue.empty()){
        auto current_guest=waiting_queue.top();
        waiting_queue.pop();

        if(current_guest.arrival_time > current_minute) current_minute=current_guest.arrival_time;

        if(current_guest.remaining_minutes <= 10){
            departure_order.push_back(current_guest.member_id);
            current_minute+=current_guest.remaining_minutes;
            continue;
        }//end of branch

        int session_minutes=current_guest.remaining_minutes/2;

        current_guest.remaining_minutes=session_minutes+(current_guest.remaining_minutes & 1); //홀수처리
        current_minute+=session_minutes;
        current_guest.arrival_time=current_minute;

        waiting_queue.push(current_guest);
    }//end of loop

    return departure_order;
}//end of compute_departure_order

void print_departure_order(const vector<int> & departure_order){
    for(const auto & member_id:departure_order)
        cout<<member_id<<'\n';
}//end of print_departure_order


int main(){
    WaitingQueue waiting_queue=read_waiting_queue();

    vector<int> departure_order=compute_departure_order(waiting_queue);

    print_departure_order(departure_order);
}//end of main