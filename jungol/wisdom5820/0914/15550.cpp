#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {
    int K;
    cin >> K;

    for(int i = 0; i < K; i++) {
        int n, m;
        cin >> n >> m; // n : 작업 개수, m : 내 작업 위치

        deque<pair<int, int>> dq;
        priority_queue<int> pq; // 가장 높은 우선순위를 찾기 위함
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;

            dq.push_back({x, j}); // 우선순위, 인덱스
            pq.push(x); 
        }

        int cnt = 0;
        int highest = pq.top();
        while(true) {
            cnt++;

            if(dq.front().first == highest) { // dq.front()의 priority가 가장 높은 우선순위인지 확인
                if(dq.front().second == m) { // 내 작업이면 끝!
                    break;
                } else {
                    pq.pop();
                    highest = pq.top(); // 가장 높은 우선순위 새로고침
                }
            } else {
                dq.push_back(dq.front()); // front 빼서 back으로 넣어주기
            }
            dq.pop_front();  
        }

        cout << cnt;
    }
    
    return 0;
}