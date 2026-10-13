#include <bits/stdc++.h>
#include <ranges>

using namespace std;

#define Is_include(v1, v2) do{if(ranges::includes((v1), (v2))) cout<<"include"<<'\n'; else cout<<"Not include"<<'\n';}while(0)
int main(){
    vector<int> v1{1,2,3,4,5};
    vector<int> v2{3,2,1};

    Is_include(v1,v2);

    ranges::sort(v1);
    ranges::sort(v2);

    Is_include(v1,v2);

    ranges::sort(v1, greater<>());
    ranges::sort(v2, greater<>());

    Is_include(v1,v2);

    if(includes(v1.begin(), v1.end(), v2.begin(), v2.end(),greater<>())) cout<<"include"<<'\n';
    else                                                                 cout<<"Not include"<<'\n'; //함수의 정렬방식이 include의 비교 기준과도 같아야한다.

    vector<int> v3{1,1,2,3};
    Is_include(v1,v3);
}