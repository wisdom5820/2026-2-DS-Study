/*

1. 사용한 AI (model 까지) :
    Chat GPT 6 Astra

2. 과제에서 활용한 부분 :
    grid를 활용한 queue 문제 해결 아이디어 질문 용도

3. 어떤 도움이 필요했는지 :
    먼저 이중 vector를 이용하여 Map을 만드는 것은 확인하였으나, 방향 전환이 있을 경우를 어떻게 고려해야할 지에 대해 도움이 필요했습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    아예 Dist라는 삼중 vector에 들어가는 원소를 x값 y값 방향값으로 둠으로써, 앞서 있었던 방향과 앞으로 들어오는 방향값이 서로 다른 경우에만
    t를 더하는 식(d와 nd가 다르다면 t를 더함)으로 해결할 수 있었습니다.

*/

#include<bits/stdc++.h>
using namespace std;

queue<array<int, 3>> Q;
vector<vector<int>> dir {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> Map;
vector<vector<vector<int>>> Dist;
int N, t;

void input() {

    cin >> N >> t;
    Map.resize(N, vector<int>(N,0));

    Dist.resize(N, vector<vector<int>>(N,vector<int>(4, -1))); // -1 미방문

    for (vector<int>& row : Map)
        for (int& element : row)
            cin >> element;

    for (int d = 0; d < 4; d++) {
        Dist[N-1][0][d] = 0;
        Q.push({N-1, 0, d});
    }
}

void queue_recursion() {
    while (!Q.empty()) {
        auto [r, c, d] = Q.front();
        Q.pop();

        for (int nd = 0; nd < 4; nd++) {
            int nr = r + dir[nd][0];
            int nc = c + dir[nd][1];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            if (Map[nr][nc] == 1)
                continue;

            int newTime = Dist[r][c][d] + 1;

            if (d != nd)
                newTime += t;

            if (Dist[nr][nc][nd] == -1 || newTime < Dist[nr][nc][nd]) {
                Dist[nr][nc][nd] = newTime;
                Q.push({nr, nc, nd});
            }
        }
    }
}

void output() {
    int answer = -1;
    for (int d = 0; d < 4; d++) {
        int value = Dist[0][N-1][d];
        if (value != -1 && (answer == -1 || value < answer))
            answer = value;
    }
    cout << answer;
}

int main() {
    input();
    queue_recursion();
    output();
}
