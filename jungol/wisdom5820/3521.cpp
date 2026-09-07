#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v(5);
    v[0].first = 1;
    v[1].first = 2;
    v[2].first = 4;
    v[3].first = 8;
    v[4].first = 16;

    for(auto& p : v) {
        cin >> p.second;
    }

    int N;
    cin >> N;

    int index = 4, cnt = 0;
    while(true) {
        if(v[index].second == 0 || v[index].first > N) {
            index--;
            continue;
        }

        N -= v[index].first;
        v[index].second--;
        cnt++;

        //cout << N << '\n';

        if(N <= 0 || (index == 0 && v[index].second == 0)) break;
    }

    // result
    if(N>0) cout << "impossible";
    else    cout << cnt;    
    
    return 0;
}