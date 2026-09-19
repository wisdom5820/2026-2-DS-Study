#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;
    for(int i = 0; i < N; i++) {
        char order;
        cin >> order;

        if(order == 'i') {
            int num;
            cin >> num;
            s.push(num);
        } else if(order == 'o') {
            if(s.empty()) cout << "empty\n";
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if(order == 'c') {
            cout << s.size() << '\n';
        }
    }

    return 0;
}