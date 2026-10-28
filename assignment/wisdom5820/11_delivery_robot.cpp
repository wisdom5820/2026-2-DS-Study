/*
- 사용한 AI : ChatGPT

- 과제에서 활용한 부분 : 다익스트라 알고리즘을 이용한 배달 로봇의 최단 이동 시간 계산

- 어떤 도움이 필요했는지 : 
    priority_queue, 3차원 dist 배열의 역할을 이해하는 데 도움을 받았다.

- AI를 통해 추가, 개선한 부분 : 
    힌트를 바탕으로 직접 코드를 구현하고, 우선순위 큐의 음수 시간 처리, 오래된 경로 건너뛰기, 최단 시간 갱신 및 도달 불가능한 경우의 출력 조건을 점검하고 수정하였다.
*/

#include <bits/stdc++.h>
using namespace std;

int N, t;

int main() {
    cin >> N >> t;

    // N x N 그리드
    int grid[25][25];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // 상하좌우 배열
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상, 하, 좌, 우

    // 최단 시간 배열
    int dist[25][25][4];

    // dist 배열 초기화
    fill(&dist[0][0][0], &dist[0][0][0] + 25*25*4, 1e9);

    // 우선순위 큐
    priority_queue<array<int, 4>> pq; // 시간, 현재 x, 현재 y, 방향

    int startX = N-1, startY = 0;

    for(int d = 0; d < 4; d++) {
        dist[startX][startY][d] = 0;
        pq.push({0, startX, startY, d});
    }

    while(!pq.empty()) {
        // 가장 시간이 적게 걸리는 상태 꺼내기
        auto [time, x, y, d] = pq.top();
        pq.pop();
        time = -time;

        // 불필요한 탐색 (오래된 경로) 건너뛰기
        if(time > dist[x][y][d]) continue;

        // 현재 위치에서 상하좌우 탐색
        int newtime;
        for(int nd = 0; nd < 4; nd++) {
            int nx = x + dir[nd][0];
            int ny = y + dir[nd][1];

            if(nx < N && nx >= 0 && ny < N && ny >= 0 && grid[nx][ny] == 0) {
                if(d == nd)
                    newtime = time + 1;
                else
                    newtime = time + 1 + t;

                if(newtime < dist[nx][ny][nd]) {
                    dist[nx][ny][nd] = newtime;
                    pq.push({-newtime, nx, ny, nd});
                }
            }
        }
    }

    int answer = 1e9;
    for(int i = 0; i < 4; i++) 
        answer = min(answer, dist[0][N-1][i]);
    
    if(answer == 1e9) cout << "-1";
    else             cout << answer;
    
}