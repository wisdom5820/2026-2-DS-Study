#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    multiset<int> price;

    cin>>N;

    while(N--){
        int p;

        cin>>p;

        price.insert(p);
    }

    int Q;

    cin>>Q;

    while(Q--){
        long long total=0;
        int x,y;
        string event;

        cin>>event;

        if(event=="INFLATION"){
            multiset<int> copy_set;
            
            cin>>x;

            for(auto it=price.begin(); it!=price.end(); ++it)
                copy_set.insert(*it+x);

            price.swap(copy_set);
        }

        if(event=="SET"){
            int num;

            cin>>x>>y;

            num=price.count(x);
            price.erase(x);

            while(num--)
                price.insert(y);
        }

        for(auto a: price)
            total+=a;

        cout<<total<<'\n';
    }
}