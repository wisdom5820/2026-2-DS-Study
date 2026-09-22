#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> request(N);
    array<queue<int>, 2> line;

    for (int& w : request)
        cin >> w;

    auto& [a, b] = line;

    vector<pair<string, int>> operations;
    operations.reserve(2 * N);

    int next = 1; 

    for (int x : request) {
        if (x >= next) {
            while (next < x) {
                a.push(next++);
                operations.emplace_back("IN", 2);
            }

            b.push(next++);
            operations.emplace_back("IN", 1);
        }

        if (!a.empty()&&a.front() == x) {
            a.pop();
            operations.emplace_back("OUT", 2);
        }
        else if (!b.empty()&&b.front() == x) {
            b.pop();
            operations.emplace_back("OUT", 1);
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    cout << 2*N<< '\n';

    for (auto [command, number] : operations)
        cout << command << ' ' << number << '\n';
}