#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,T,i,j, time;

    cin>>T;
    while(T--){
        queue<pair<int, int>> printer;//priority queue는 같은 값의 자료들을 구분하는 방법이 존재하지 않는다.
        priority_queue<int> priorities;

        time=0;

        cin>>n>>m;

        for(i=0; i<n; i++){
            cin>>j; 
            
            printer.push({j, i});
            priorities.push(j);
        }

        while(!printer.empty()){
            auto [priority, index]=printer.front();

            printer.pop();

            if(priority<priorities.top()){
                printer.push({priority, index});
                continue;
            }

            priorities.pop();
            ++time;

            if(index==m){
                cout<<time<<'\n';
                break;
            }
        }
    }
}