/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: 전박적으로 check_move 함수를 구성함에 도움 받았다. 
3. 어떤 도움이 필요했는지: 처음에는 어떻게해야 최소 시간을 찾을 수 있는지 조차 감이 오지않아
전박적으로 어떻게 해야 도착지점까지 최소거리를 구할 수 있는지 묻고 코드 작성에도 많은 도움을 받았습니다.
4. AI 제시 코드에서 추가, 개선한 부분: 전체적으로 쓸데 없었던 부분을 문제 조건에 따라 제거하였다.
runtime에 결정되던 vector의 크기를 문제에 따라 고정 배열로 바꿨고 컨테이너와 핵심 변수들을 전역
으로 선언하여 전달 인자를 줄였다.
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1'000'000'000;

int space_size, t_spin;
int space[25][25], min_time[25][25][4];
queue<array<int, 3>> check;

void check_move(int row, int col, int dir) {
    // 위, 오른쪽, 아래, 왼쪽
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int t_current = 0;

    if (dir != -1)
        t_current = min_time[row][col][dir];

    for (int next_dir = 0; next_dir < 4; ++next_dir) {
        int nr = row + dr[next_dir];
        int nc = col + dc[next_dir];

        if (nr < 0 || nr >= space_size || nc < 0 || nc >= space_size) continue;
        if (space[nr][nc] == 1) continue;

        int next_time = t_current + 1;

        if (dir != -1 && dir != next_dir) next_time += t_spin;

        if (next_time < min_time[nr][nc][next_dir]) {
            min_time[nr][nc][next_dir] = next_time;
            check.push({nr, nc, next_dir});
        }
    }
}

int main() {
    cin >> space_size >> t_spin;

    for (int i = 0; i < space_size; ++i)
        for (int j = 0; j < space_size; ++j) {
            cin >> space[i][j];

            for (int dir = 0; dir < 4; ++dir)
                min_time[i][j][dir] = INF;
        }

    for (int dir = 0; dir < 4; ++dir)
        min_time[space_size - 1][0][dir] = 0;

    check.push({space_size - 1, 0, -1}); //첫 이동에 대한 예외처리를 하지 않으면 회전 비용이 발생하는 문제가 있다.

    while (!check.empty()) {
        array<int, 3> now = check.front();
        check.pop();

        check_move(now[0], now[1], now[2]);
    }

    int answer = INF;

    for (int dir = 0; dir < 4; ++dir)
        answer = min(answer, min_time[0][space_size - 1][dir]);

    if (answer == INF) cout << -1; //경로가 없다.
    else cout << answer; //정답
}