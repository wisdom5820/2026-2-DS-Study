#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i,val,stand, cnt;
    stack<int> S;

    cin>>n;

    for(i=0; i<n; i++){
        cin>>val;
        S.push(val);
    }

    stand=S.top();
    S.pop();

    cnt=1;

    for(i=0; i<n-1; i++){
        if(stand<S.top()){
            cnt++;
            stand=S.top();
        }
        S.pop();
    }

    cout<<cnt;
}