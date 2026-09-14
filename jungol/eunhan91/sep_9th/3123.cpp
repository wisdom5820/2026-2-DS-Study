#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, cur,i;
    string str, pass_word;
    vector<string> log;
    cin>>T;

    for(i=0; i<T; i++){
        cin>>str;
        log.push_back(str);
    }

    for(i=0; i<T; i++){
        string pass_word="";
        cur=0;

        for(char c: log[i])
            switch (c){

            case 45: //-
                if(cur>0){
                    pass_word.erase(cur-1,1);
                    cur--;
                }
                break;

            case 60: //<
                if(cur>0) cur--;
                break;
            case 62: //>
                if(cur<pass_word.size()) cur++;
                break;
            default:
                pass_word.insert(pass_word.begin()+cur,c);
                cur++;
                break;
        }

        cout<<pass_word<<'\n';
    }
    
}
