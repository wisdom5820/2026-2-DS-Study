/*
- 사용한 AI : ChatGPT

- 과제에서 활용한 부분 : stack을 활용한 컨테이너 재배치 로직 구현 과정에서 오류 점검

- 어떤 도움이 필요했는지 : 
    원래는 가장 높은 적치장의 컨테이너들을 priority_queue에 모은 뒤 가장 낮은 적치장으로 옮기는 방식으로 구현했으나, 
    foundL 값이 반복문 안에서 초기화되지 않아 무한 루프가 발생했다.

- AI를 통해 추가, 개선한 부분 :  
    AI의 도움을 받아 해당 오류의 원인을 확인하고, 매 이동마다 가장 높은 적치장의 top 컨테이너 중 가장 무거운 하나를 
    선택하여 가장 낮은 적치장으로 옮기는 방식으로 로직을 수정하였다. 또한 컨테이너 이동에 따라 highest와 lowest를 
    다시 계산하도록 개선하였다.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    // 입력
    int N;
    cin >> N;

    vector<stack<int>> yard(N);
    // int highest = 0, lowest = INT_MAX; // while문을 반복할 때마다 계산하도록 이동

    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;

        for(int j = 0; j < t; j++) {
            int ton;
            cin >> ton;
            yard[i].push(ton);
        }

        // highest = max(highest, t);
        // lowest = min(lowest, t);
    }

    // bool foundH, foundL; 
    
    // 재배치
    while(true) { 
        int highest = 0, lowest = INT_MAX;

        for(auto& stk : yard) {
            highest = max(highest, (int)stk.size());
            lowest = min(lowest, (int)stk.size());
        }

        if(highest - lowest <= 1) break;

        int from = -1;
        for(int i = 0; i < N; i++) {
            if(yard[i].size() == highest) {
                if(from == -1 || yard[i].top() > yard[from].top())
                    from = i;
            }
        }

        int to = -1;
        for(int i = 0; i < N; i++) {
            if(yard[i].size() == lowest) {
                to = i;
                break;
            }
        }

        yard[to].push(yard[from].top());
        yard[from].pop();
    }
    
    // 출력
    for(auto stk : yard) {
        if(stk.empty()) {
            cout << 0 << '\n';
            continue;
        }
        
        vector<int> temp;

        while(!stk.empty()) {
            temp.push_back(stk.top());
            stk.pop();
        }

        reverse(temp.begin(), temp.end());
        for(int i : temp) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}