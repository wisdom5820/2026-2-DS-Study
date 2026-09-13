#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, n;
    cin >> K;

    vector<vector<pair<int,int>>> v(K);
    for(int i = 0; i < K - 1; i++) {
        while(cin >> n, n != -1) {
            v[i].push_back({n, 1});
            v[i+1].push_back({n, 0});
        }
    }

    for(auto& x : v) sort(x.begin(), x.end());

    // [AI] map 대신 vector<char>를 사용하도록 수정하여 코드를 간소화함
    vector<char> r(K);
    for(int i = 0; i < K; i++){
        int l = i, j = 0;
        while(j < v[l].size()){
            auto [n, d] = v[l][j];
            l += d ? 1 : -1;
            // [AI] find_if 대신 upper_bound를 사용하여 현재 교차점 다음 위치를 찾도록 수정함
            j = upper_bound(v[l].begin(), v[l].end(), pair<int, int>{n, 1}) - v[l].begin();
        }
        r[l] = 'a' + i;
    }
    for(char c : r) cout << c << ' ';
}

// [AI] pair의 first 값으로 원소를 찾는 방법을 질문하여 find_if 사용법을 확인함
// [AI] 코드 토큰 수를 줄이기 위해 find_if를 upper_bound로 변경함
// [AI] map 대신 vector<char>를 사용하여 결과 저장 구조를 단순화함