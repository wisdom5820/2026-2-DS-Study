#include<bits/stdc++.h>

using namespace std ;

int main () {
    stack<int> stck;
    int N;
    cin >> N;
    for(int i =0; i<N;i++){
        string s;
        cin >> s;
        if (s == "i"){
            int a;
            cin >> a;
            stck.push(a);
        }
        else if (s == "o"){
            if (stck.size() == 0){
                cout << "empty" << endl;
            }
            else{
                cout << stck.top() << endl;
                stck.pop();
            }
        }
        else if( s == "c"){
            cout << stck.size() << endl;
        }
    }
}
