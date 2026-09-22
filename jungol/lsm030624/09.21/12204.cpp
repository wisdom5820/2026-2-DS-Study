#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N + 1);
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        pos[A[i]] = i; 
    }

    vector<int> lane(N + 1, 0);

    int last_pos1 = 0, last_pos2 = 0;
    bool possible = true;


    for (int i = 1; i <= N; i++) {
        int cur_p = pos[i];


        bool can1 = (cur_p > last_pos1);
        bool can2 = (cur_p > last_pos2);

        if (can1 && can2) {
            if (last_pos1 >= last_pos2) {
                lane[i] = 1;
                last_pos1 = cur_p;
            } else {
                lane[i] = 2;
                last_pos2 = cur_p;
            }
        } else if (can1) {
            lane[i] = 1;
            last_pos1 = cur_p;
        } else if (can2) {
            lane[i] = 2;
            last_pos2 = cur_p;
        } else {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO\n";
        return 0;
    }

    vector<string> ops;
    queue<int> q1, q2;
    int next_in = 1;
    int out_ptr = 1;

    while (out_ptr <= N) {
        int target = A[out_ptr];

        if (!q1.empty() && q1.front() == target) {
            q1.pop();
            ops.push_back("OUT 1");
            out_ptr++;
        } else if (!q2.empty() && q2.front() == target) {
            q2.pop();
            ops.push_back("OUT 2");
            out_ptr++;
        } else if (next_in <= N) {
            int l = lane[next_in];
            if (l == 1) q1.push(next_in);
            else q2.push(next_in);
            ops.push_back("IN " + to_string(l));
            next_in++;
        } else {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ops.size() << "\n";
        for (const string& op : ops) {
            cout << op << "\n";
        }
    }

    return 0;
}
