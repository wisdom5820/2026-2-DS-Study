/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: 29행의 while문의 전체적으로 도움을 받았다.
3. 어떤 도움이 필요했는지: 첫 코드의 design부터 TLE가 발생하지 않기 위해서는 합을 저장하면서 depth기반 탐색을 하는 즉 DP DFS형식으로 구현하기로 결정하였고 구현시 발생할 수 있는 예외 상황 추가 체크 로직 에러등을 해결하는데 큰 도움을 받았다.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_constants, result;

    cin >> n_constants;

    vector<int> constants(n_constants);

    for (auto& w : constants) cin >> w;
    cin >> result;

    vector memo(n_constants + 1, vector<int>(result + 1, -1)); //memo[idx][sum]에 대하여 value가 0이면 계산 완료된 곳 -1이면 이계산
    stack<pair<int, int>> state; //현재위치 depth와 sum을 저장한다. 
    
    state.push({0, 0});

    while (!state.empty()) {
        auto [idx, sum] = state.top();

        if (memo[idx][sum] != -1) state.pop(); 

        else if (idx == n_constants) memo[idx][sum] = (sum == result); //모든값 처리완료

        else if (constants[idx] > result - sum) memo[idx][sum] = 0;

        else {
            int temp = sum + constants[idx];
            if (memo[idx][temp] == -1) state.push({idx, temp});

            else if (memo[idx + 1][temp] == -1) state.push({idx + 1, temp});

            else memo[idx][sum] = (memo[idx][temp] + memo[idx + 1][temp]) % 19991;
        }
    }
    cout << memo[0][0];
}