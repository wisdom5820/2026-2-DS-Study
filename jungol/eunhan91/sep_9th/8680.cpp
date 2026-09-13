#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int open,close, N, i, diff, max;
    char val;
    stack<char> parent;

    open=close=0;
    cin>>N;


    for(i=0; i<N; i++){
        cin>>val;

        if(val=='(') open++;
        else close++;//전체에서 열린 것과 닫힌 것의 수 

        parent.push(val);
    }

    max=diff=close-open;

    while(!parent.empty()){
        if(parent.top()=='(') diff++;
        else diff--;

        if(max<diff) max=diff;

        parent.pop();
    }
     
    cout<<(max+1)/2;
}