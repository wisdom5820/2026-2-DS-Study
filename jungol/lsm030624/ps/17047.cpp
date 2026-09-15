#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); // ios_base::sync_with_stdio(false);
    cin.tie(0); // cin.tie(NULL);
    int N;
    cin >> N;
    int END;
    int pop_c = 0;
    int push_c = 0;
    stack<int> s;
    while (END != -1){
        cin >> END;
        if (END == 0){
            if (s.size()>0)
                s.pop();
            else
                pop_c++;
        }
        else{
            if (END != -1){
                s.push(END);
            }
        }
    }
    long long sum = 0;
    int id = 0;
    int sz = s.size();
    while (id < sz){
        sum = sum + s.top();
        s.pop();
        id++;
    }
    if (pop_c){
        cout << "say: There were too many cancellations." << "\n";
    }
    else{
        if (N > sz){
            cout << "say: It`s less than my working days" << "\n";
        }
        else if (N < sz){
            cout << "think: oh yes!!!" << "\n";
            cout << sum;
        }
        else{
            cout << sum;
        }
    }
}
