#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Vv;
typedef vector<int> V;
typedef long long Dlong;

V multiples_below_R(int start, int R){
    V temp;

    for(int i=1; i*start<R; ++i)
        temp.push_back(i*start);

    return temp;
}

Dlong calc_n_solutions(const Vv & all){
    stack<int> branch;
    Dlong total;

    function<void()> check_all_branch=[&](){
        
    }
}

int main(){
    int n_var,result;
    Vv all_multiples;

    cin>>n_var;
    
    V constants(n_var);

    for(auto &w:constants)
        cin>>w;
    cin>>result;
    /*input()*/

    for(int i=0; i<n_var; ++i)
        all_multiples.push_back(multiples_below_R(constants[i], result));
    /*prepro()*/

    Dlong n_solutions=calc_n_solutions(all_multiples);
    /*compute()*/

    cout<<n_solutions%19991;
    /*output()*/
}