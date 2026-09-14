#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k, N;
    string S;
    cin>>T>>k;

    while(T--){
        cin>>N>>S;

        cout<<"YES"<<'\n';

        if(k==0) continue;

        for(int i=0; i<N-1; i++){//범위초과 방지
            if(S[i]==S[i+1]) cout<<'M';

            else cout<<'O';
        }

        cout<<S.back()<<'\n';
    }

}