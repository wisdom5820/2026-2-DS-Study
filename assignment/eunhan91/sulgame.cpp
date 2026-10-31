/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: compute_who_will_drink 함수의 전반을 도움받았다.
3. 어떤 도움이 필요했는지: v 1.0의 함수에서 볼 수 있듯 erase 연산이 vector에 시행되었을 때 생길 수 있는 여러가지
오버헤드에 대하여 느슨하게 관리하였다. 때문에 대부분의 상황에서 TLE가 발생하였고 이에 대하여 AI에게 조언을 구하니
제곱근 분할법으로 구현하게 되었다. 처음 사용해보는 방법인 만큼 인덱스를 관리하고 소유권을 가진 실제 벡터를 다룸에 있어
도움 받았다.
4. AI 제시 코드에서 추가, 개선한 부분:해당사항 없음, 제곱근 분할의 개념에 대한 질문과 구현 과정에서 생겼던 오류들의
원인들에 대한 이야기만 들었습니다. 후에 구현은 직접 작성하였습니다.
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> GUEST, CNT;
int REMAIN, BOUND, LOCATION;

class LocalRandom {
    private: uint32_t state;

    public:
        explicit LocalRandom(int key) {
            state = static_cast<uint32_t>(key);
        }

        uint32_t next() {
            state = state * 1664525u + 1013904223u;
            return state;
        }
};

vector<int> get_seat(int p, int q, int key) {
    if (q < p) {cerr << "\nBound p,q error"; exit(1); }

    vector<int> Guest;
    for (int i = p; i <= q; i++) Guest.push_back(i);
        LocalRandom rng(key);
 
    for (int i = (int)Guest.size() - 1; i > 0; i--) {
        int j = rng.next() % (i + 1);
        swap(Guest[i], Guest[j]);
    }
    return Guest;
}
/*  v 1.0
void compute_who_will_drink(){
    int offset=jump_offset%GUEST.size();

    it_to_erase=offset>=distance(it_to_erase, GUEST.end()) 
        ? GUEST.begin()+(offset-distance(it_to_erase, GUEST.end()))
        : it_to_erase+offset;
    
    jump_offset=*it_to_erase;

    GUEST.erase(it_to_erase); //UB라서 c++ 환경에서만 사용할 수 있다.
}//end of compute_who_will_drink
*/

void compute_who_will_drink(){
    int block=0, pos=LOCATION; //전위치와 블럭

    while(pos >= CNT[block]){
        pos-=CNT[block]; //CNT에서 다음 LOCATION 찾기
        block++;
    }

    int idx=block*BOUND+pos, jump=GUEST.at(idx), end_idx=block*BOUND+CNT[block]; //실제 위치를 인덱스에 저장하고 jump값으로 이용
    
    auto it=GUEST.begin();
    move(it+idx+1, it+end_idx, it+idx);

    CNT[block]--;
    REMAIN--;
    LOCATION=(LOCATION+jump)%REMAIN;
}//end of compute_who_will_drink

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lower_bound, upper_bound, key;
    
    cin>>lower_bound>>upper_bound>>key;
    //input()
    GUEST=get_seat(lower_bound, upper_bound, key);

    REMAIN=GUEST.size();
    BOUND=sqrt(REMAIN);

    int block=(REMAIN+BOUND-1)/BOUND;
    LOCATION=GUEST.front()%REMAIN;

    CNT.assign(block, BOUND);
    CNT.back()=REMAIN-(block-1)*BOUND;
    //prepro()
    
    while(REMAIN!=1)
        compute_who_will_drink();
    //compute()

    for(int i=0; i<CNT.size(); ++i)
        if(CNT[i]!=0) cout<<GUEST[i*BOUND];
    //oupute() find the winner of sulgame!!
}//end of main
