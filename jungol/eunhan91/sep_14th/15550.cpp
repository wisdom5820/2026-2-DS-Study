#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,T,i,j;
    long long time=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> printer;//priority queue는 같은 값의 자료들을 구분하는 방법이 존재하지 않는다.

    cin>>T;
    while(T--){
        cin>>n>>m;

        for(i=0; i<n; i++){
            cin>>j; 
            
            printer.push({j, i});
        }

        while(true){
            if(printer.top().second==m) break;

            printer.pop();
            time+=1;
        }
        
        cout<<time<<'\n';
    }
}