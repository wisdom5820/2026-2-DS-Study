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

}