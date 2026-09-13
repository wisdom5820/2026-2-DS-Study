#include <bits/stdc++.h>
using namespace std;

// [AI]
// HW02에서는 참가자가 사다리를 직접 내려가는 방식으로 구현했다. 
// 하지만 일반 사다리에서는 토큰 수가 너무 많아져서 새로운 로직을 고민하게 되었다.
// 이 과정에서 AI를 통해 가로막대의 양 끝 참가자를 교환하는 방식으로 문제를 단순화할 수 있다는 아이디어를 얻었다.

int main() {
    int N, d;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N - 1; i++) {
        while (cin >> d, d != 0) v.push_back({d, i});
    }

    sort(v.begin(), v.end());

    vector<char> result(N);
    for (int i = 0; i < N; i++) result[i] = 'A' + i;

    int idx = 0;
    while (idx < v.size()) {
        int depth = v[idx].first, start = v[idx].second, end = start;

        idx++;

        while (idx < v.size() && v[idx].first == depth && v[idx].second == end + 1) {
            end = v[idx].second;
            idx++;
        }
        // [AI] 긴 가로막대에서는 중간 위치는 그대로 내려가므로 양 끝의 참가자만 교환하면 됨을 확인함
        swap(result[start], result[end + 1]);
    }

    for (char x : result) cout << x << ' ';

    return 0;
}