#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[5]={1,2,3,4,5};
    int b[4]={1,2,3,4};

    if(equal(b,b+4,a)) cout<<"equal!";
    else               cout<<"Not equal!";

    cout<<'\n';

    if(equal(a,a+4,b)) cout<<"equal!";
    else               cout<<"Not equal!";

    /*
    같은 컨테이너를 대상으로 하더라도 어떤 값을 src로 잡고 어떤값을 dest로 잡냐에 따라 결과가 바뀔 수 있다.
    reference:Generic_algo - equal(  ).cpp
    */
}