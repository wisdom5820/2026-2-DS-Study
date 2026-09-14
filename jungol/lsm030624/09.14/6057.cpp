#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); // ios_base::sync_with_stdio(false);
    cin.tie(0); // cin.tie(NULL);
    int P, N;
    cin >> P >> N;
    vector<queue<pair<int, int>>> que(P);

    int sum = 0;

    for (int i = 0; i< N; i++){
        int cmd, p, m;
        cin >> cmd;
        if (cmd == 0) cin >> p >> m;
        else cin >> p;
        switch(cmd){
            case 0:
                que[p-1].push({p, m});
                break;
            case 1:
                if (que[p-1].size() > 0){
                    sum = sum + que[p-1].front().second;
                    que[p-1].pop();
                }
                break;
        }
    }
    cout << sum;
}

