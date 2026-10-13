#include <bits/stdc++.h>

using namespace std;

#define all_out(x) do{cout<<#x<<" "; for(auto w:(x)) cout<<w<<" ";}while(0);
int main(){
    vector<int> v{1,2,3,4,5,6,7};

    adjacent_difference(v.begin(), v.end(), v.begin());

    all_out(v)
    /*
    dajacent_difference는 previous 값을 백업한다.
    reference:Generic_algo - adj_difference 1(b).cpp
    */
}