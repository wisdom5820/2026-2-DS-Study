/*
    1. 사용한 AI: ChatGPT
    2. 과제에서 활용한 부분: 우선순위 비교 조건 및 예외 상황 처리
    3. 어떤 도움이 필요했는지: 
        직접 작성한 코드에서 문제의 조건을 충족하지 못하는 부분과 논리적 오류를 확인하고자 함.
    4. AI를 통해 추가·개선한 부분:
        - 남은 상담 시간이 같을 경우 대기실 입장 시간이 빠른 사람을 우선하도록 비교 연산자를 수정함.
        - 홀수 상담 시간에서 발생하는 시간 손실을 방지하기 위해 남은 상담 시간을 guestTime - guestTime / 2로 수정함.
        - 대기실이 비어 있어도 이후 도착할 손님이 남아 있다면 다음 손님의 도착 시간으로 이동하도록 반복문을 개선함.
*/

#include <bits/stdc++.h>
using namespace std;

struct Guest {
    int in; // 들어온 시간
    int id; // 번호
    int time; // 상담 시간 (러닝타임)

    bool operator<(const Guest& other) const {
        if (time != other.time)
            return time < other.time; // 남은 상담 시간이 긴 사람 우선
        
        return in > other.in; // 대기실에 먼저 들어온 사람 우선
    }
};

int main() {
    int N;
    cin >> N;
    
    queue<Guest> ready;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        ready.push({a, b, c}); 
    } // 시간 순서대로 손님이 들어간다

    priority_queue<Guest> center; 

    int currentTime = 30;

    // 초기 상황 세팅 (30분 전에 도착한 사람들만 먼저 들여보내기)
    while(!ready.empty() && ready.front().in <= currentTime) { 
        center.push(ready.front());
        ready.pop();
    }

    // 현재 대기실에 손님이 남아있거나(!center.empty())
    // 아직 도착하지 않은 손님이 있다면(!ready.emtpy())
    // 계속 반복
    while(!center.empty() || !ready.empty()) {

        // 대기실이 비어 있는 경우
        if (center.empty()) {
            currentTime = max(currentTime, ready.front().in); // 다음 손님이 도착하는 시간으로 이동
            center.push(ready.front()); // 그 손님 대기실에 넣기
            ready.pop();
        }

        Guest currentGuest = center.top();
        center.pop();

        int guestTime = currentGuest.time;

        if (guestTime <= 10) { // 이때 손님 탈출 -> 출력까지
            currentTime += guestTime;
            cout << currentGuest.id << '\n';
        } 
        else {
            currentTime += guestTime / 2;
            center.push({currentTime, currentGuest.id, guestTime - guestTime / 2});
        }

        // 손님 더 들어오세요
        while(!ready.empty() && ready.front().in <= currentTime) {
            center.push(ready.front());
            ready.pop();
        }
    }
}