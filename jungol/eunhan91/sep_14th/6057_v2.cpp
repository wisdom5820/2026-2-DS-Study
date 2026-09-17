#include <bits/stdc++.h>

using namespace std;//FIFO 순회도 필요하다 deque가 적절한 DS

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, N;
    long long total=0;

    cin>>P>>N;

    vector<deque<int>> pizza(P+1);

    while(N--){
        int cmd, p, m;

        cin>>cmd>>p;

        if((bool)cmd){
            if(pizza[p].empty())
                continue;
            total+=pizza[p].front();
            pizza[p].pop_front();
        }

        else{
            cin>>m;
            pizza[p].push_back(m);
        }        
    }

    cout<<total;
}