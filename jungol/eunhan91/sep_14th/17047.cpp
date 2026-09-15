#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,work, cnt;
    long long total;
    stack<int> record;

    cnt=total=0;

    cin>>work;

    while(cin>>N, N>=0){
        
        
        if(!record.empty() && N==0){
            record.pop();
            cnt--;
            continue;
        }

        if(record.empty() && N==0){
            cout<<"say: There were too many cancellations.";
            return 0;
        }

        record.push(N);

        cnt++;
    }

    while(!record.empty()){
        total+=record.top();
        record.pop();
    }

    if(work>cnt)
        cout<<"say: It`s less than my working days";
    

    else if(work==cnt){
        cout<<total;
    }

    else
        cout<<"think: oh yes!!!"<<'\n'<<total;
}