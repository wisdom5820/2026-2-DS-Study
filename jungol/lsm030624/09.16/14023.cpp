#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); // ios::sync_with_stdio(false);
    cin.tie(0); // cin.tie(nullptr);
    long long N, p, Q;
    cin >> N;
    long long temp = 0;
    map<long long, long long> m;
    for (int i =0; i<N; i++) {
        cin >> p;
        m[p] += 1;
        temp += p;
    }
    cin >> Q;

    long long offset = 0;
    while (Q--) {
        string s;
        long long x, y;
        cin >> s;

        if (s == "INFLATION") {
            cin >> x;
            offset += x;
            temp += x * N;
        } else {
            cin >> x >> y;
            long long t = m[x-offset];
            m[x-offset] -= t;
            m[y-offset] += t;

            temp += (y - x) * t;
        }

        cout << temp << "\n";

    }
}
