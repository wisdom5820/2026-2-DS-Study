#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char option;
    int N,i,value;
    stack<int> S;
    cin>>N;


    for(i=0; i<N; i++){
        cin>>option;

        switch (int(option))
        {
        case 99://c
            cout<<S.size()<<"\n";
            break;
        
        case 105://i
            cin>>value;
            S.push(value);
            break;
        case 111://o
            if(S.empty())
                cout<<"empty"<<"\n";
            else{
                cout<<S.top()<<"\n";
                S.pop();
            }
        }
    }
}