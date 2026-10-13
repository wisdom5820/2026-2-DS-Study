#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v1(7,0), v2(10,0);

    cout<<"size of Vectors is";
    cout<<"\nv1="<<v1.size();
    cout<<"\nv2="<<v2.size();

    swap(v1, v2);

    cout<<"\nAfter swap size of Vectors is";
    cout<<"\nv1="<<v1.size();
    cout<<"\nv2="<<v2.size();

    /*
    벡터의 내용만 바꾸는 함수가 아니다.
    reference:Generic_algo - swap( ).cpp
    */
}