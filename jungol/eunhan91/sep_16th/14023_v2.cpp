#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    map<long long, long long> foods;//가격 개수

    cin>>N;

    while(N--){
        int p;

        cin>>p;

        ++foods[p];
    }

    int Q;
    long long b=0;

    cin>>Q;

    while(Q--){
        long long total=0;

        for(auto a:foods)
            total+=a.first*a.second;
        
        long long x,y;
        string event;

        cin>>event;

        if(event=="INFLATION"){
            cin>>x;

            b+=x;
            total+=x*foods.size();
        }

        if(event=="SET"){
            cin>>x>>y;

            auto it=foods.find(x-b);

            if(it != foods.end()){
                long long quantity=it->second;
                foods.erase(it);

                foods[y-b]+=quantity;
                total+=(y-x)*quantity;
            }
        }
        
        cout<<total<<'\n';
    }
}