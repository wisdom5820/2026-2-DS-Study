#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, i,k,x;
    char j;
    map<int, int> m;

    cin>>n;

    while(n--){
        cin>>i>>j>>k;

        if(j=='L') k=-k;

        m.emplace(i, i+k); //(3,4) (0,-2) (7,2) (-2, 3)
    }

    cin>>x;

    for(i=0; i<m.size(); ++i)
        x=m[x];

    cout<<x;
}