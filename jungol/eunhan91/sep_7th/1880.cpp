#include <bits/stdc++.h>

using namespace std;

int main(){
    string key, sen;

    cin>>key;

    getline(cin>>ws, sen);

    for(auto &w:sen) //offset을 이용하자 
        if(isupper(w))
            w=toupper(key[w-'A']);
        else if(islower(w))
            w=key[w-'a'];
    
    cout<<sen;
}