#include <bits/stdc++.h>
using namespace std;

int main() {
    int P, NS, T;
    cin >> P >> NS >> T;

    vector<vector<int>> tree(P+1);
    vector<bool> isChild(P+1, false);

    for(int i = 0; i < NS; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back(b);
        tree[a].push_back(c);

        isChild[b] = true;
        isChild[c] = true;
    }

    // 루트 찾기
    int rootIndex;
    for(int i = 1; i <= P; i++) {
        if (!isChild[i]) {
            rootIndex = i;
            break;
        }
    }

    queue<int> q; // 다음에 탐색할 노드 저장
    vector<int> dist(P+1, -1);
    // dist[i] : 루트에서 i번 노드까지의 거리
    // -1 : 아직 방문하지 않은 노드
    vector<int> parent(P+1, -1); // 각 노드의 부모를 기록해야 함 (나중에 출력을 위해)

    q.push(rootIndex);
    dist[rootIndex] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == T) break; // 보물을 찾았을 때

        for (int next : tree[current]) {
            if(dist[next] != -1) continue; // 이미 방문한 노드면 건너뛰기

            dist[next] = dist[current] + 1; // 루트에서 다음 노드까지의 거리
            parent[next] = current; // 다음 노드로 오기 직전에 방문한 노드
            q.push(next); // 다음 노드를 탐색 대상으로 추가
        }
    }

    // 최단경로 찾기
    vector<int> path;
    int current = T;
    while (current != -1) {
        path.push_back(current); // path에 추가
        current = parent[current]; // 부모로 current를 옮김
    }

    reverse(path.begin(), path.end()); // 뒤집어서 출력

    // 출력
    cout << dist[T] << "\n";
    for (int p : path) 
        cout << p << "\n";
}