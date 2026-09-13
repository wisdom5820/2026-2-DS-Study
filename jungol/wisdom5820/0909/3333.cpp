#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.push(num);
    }

    int t = s.top();
    int can_see = 1;
    for(int i = 0; i < N-1; i++) {
        s.pop();
        if(s.top() > t) {
            can_see++;
            t = s.top();
        }
    }

    cout << can_see; 

    return 0;
}