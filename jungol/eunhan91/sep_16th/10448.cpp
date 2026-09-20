#include <bits/stdc++.h>

using namespace std;

int main(){
    int T,d;

    cin>>T;

    for(int i=1; i<=T; ++i){
        map<char, int> encoding;
        set<string> is_same;
        int n;
        

        for(int j=0; j<26; ++j){
            cin>>d;

            encoding[char('A'+j)]=d;
        }

        cin>>n;

        for(int j=0; j<n; ++j){
            string str;
            cin>>str;

            string new_str="";
            
            for(auto c:str)
                new_str+=encoding[c];
            
            is_same.insert(new_str);
        }

        cout<<"Case #"<<i<<": ";

        if(n==is_same.size()) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}