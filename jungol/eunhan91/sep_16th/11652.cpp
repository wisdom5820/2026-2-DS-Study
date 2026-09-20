#include <bits/stdc++.h>

using namespace std;

int main(){
    array<map<string, int>, 2> time;

    for(int i=0; i<2; ++i){
        while(true){
            int s,e;
            string test_string, t;

            getline(cin, test_string);

            if(test_string[0]=='-' || test_string[0]=='=') break;

            stringstream my_string(test_string);
            
            my_string>>s>>e>>t;

            time[i][t]+=e-s;
        }
    }

    if(time[0]==time[1]){ 
        cout<<"No differences found.";
        return 0;
    }

    set<string> name_of_all_member;

    for(auto [name,_]:time[0]) name_of_all_member.insert(name);
    for(auto [name,_]:time[1]) name_of_all_member.insert(name);

    for(auto name:name_of_all_member){
        if(time[0][name]==time[1][name]) continue;

        cout<<name<<" "<<showpos<<time[1][name]-time[0][name]<<'\n';
    }
}