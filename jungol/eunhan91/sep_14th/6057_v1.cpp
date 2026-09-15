#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P,N;
    long long total=0;
    deque<pair<int, int>> pizza;
    cin>>P>>N;

    while(N--){
        int cmd,p,m;

        cin>>cmd>>p;

        if(bool(cmd)){
            if(pizza.front().first==p&&!pizza.empty()){//runtime error 주의
                total+=pizza.front().second;
                pizza.pop_front();
            }

            else{
            for(auto it=pizza.begin(); it != pizza.end(); ++it){ //time over 
                if((*it).first==p){
                    total+=(*it).second;
                    pizza.erase(it);
                    break;
                }
            }
            }   
        }

        else{
            cin>>m;
            pizza.push_back({p, m});
        }

        /*switch(bool(cmd)){
            case true:
            case false:
        }*/
    }

    cout<<total;
}
