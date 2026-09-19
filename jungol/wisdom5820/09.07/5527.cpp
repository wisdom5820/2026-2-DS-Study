#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    queue<int> q;
    
    int n;
    cin >> n;

    int total_time = 0;
    for(int i = 0; i < n; i++) {
        string order;
        cin >> order;

        if(order == "call") {
            int call_minute;
            cin >> call_minute;

            q.push(call_minute);
            total_time += call_minute;
        } else if(order == "wait") {
            int wait_minute;
            cin >> wait_minute;
            
            while(wait_minute > 0 && !q.empty()) {
                if(wait_minute >= q.front()) {
                    wait_minute -= q.front();
                    total_time -= q.front();
                    q.pop();
                } else {
                    q.front() -= wait_minute;
                    total_time -= wait_minute;
                    wait_minute = 0;
                }
            }
        } else if(order == "check") {
            cout << q.size() << " people " << total_time << " minutes\n";
        }
    }
    return 0;
}