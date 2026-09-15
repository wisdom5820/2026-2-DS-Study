#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        int n, m;
        int time = 0;

        queue<pair<int,int>> arr;
        int id[10] = {0};

        cin >> n >> m;
        cin.ignore();

        string s;
        getline(cin, s);
        
        stringstream ss(s);

        int i;
        int idx = 0;

        while (ss >> i) {
            if (idx != m)
                arr.push({0, i});
            else
                arr.push({1, i});

            id[i]++;
            idx++;
        }

        while (1) {
            int a = arr.front().second;
            int b = arr.front().first;

            int check = 0;


            for (int i = a + 1; i <= 9; i++) {
                if (id[i] > 0) {
                    check = 1;
                    break;
                }
            }

            if (check == 1) {
                arr.push(arr.front());
                arr.pop();
            }
            else {
                arr.pop();
                id[a]--;
                time++;

                if (b == 1) {
                    cout << time << '\n';
                    break;
                }
            }
        }
    }
}
