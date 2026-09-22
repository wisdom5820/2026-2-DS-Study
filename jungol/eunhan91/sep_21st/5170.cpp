#include <bits/stdc++.h>

using namespace std;

typedef long long ll;//나무 높이 도합 값 즉 M과 톱 높이 H H가 찾는값

bool is_bigger(ll tree_height, vector<ll>& v,ll saw){
    ll total=0;

    for(auto t:v){
        if(saw<t) 
            total+=t-saw;
    }

    return total>=tree_height;
}

int main(){
    ll N,M,H;

    cin>>N>>M;

    vector<ll> forest;

    forest.resize(N);

    for(ll &tree:forest)
        cin>>tree;

    long long st=0,en=*max_element(forest.begin(), forest.end()),mid=(st+en)/2; //st값을 줄이면서 조사할때는 +1을 통한 올림식으로 en 값을 줄이면서 조사할때는 내림식으로 해결해야한다.

    while(st<en){
        mid=(st+en+1)/2;
        if(is_bigger(M,forest,mid)) st=mid;

        else                        en=mid-1;
    }
        
    cout<<st;
}