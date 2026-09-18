#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, pair<char, int>> m;

    for (int x = 0; x < n; x++) {
        int i, k;
        char j;

        cin >> i >> j >> k;

        m[i] = {j, k};
    }

    int N;
    cin >> N;

    for (int x = 0; x < n; x++) {
        auto [j, k] = m[N];

        if (j == 'L'){
            N -= k;
        }
        else{
            N += k;
        }
    }
    cout << N;
}

