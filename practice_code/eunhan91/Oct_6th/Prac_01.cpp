#include <bits/stdc++.h>

#define str(x) #x
#define glue(x, y) x ## y

using namespace std;

int main(){
    cout<<str(abc);
    //cout<<glue(ab, c); syntax error

    //str(cout)<<"Hello World!"; syntax error
    glue(c,out)<<"Hello world!";

    return 0;
    /*
    #은 매크로에서 받은 매개변수를 문자열로 치환하고
    ##은 두가지 매개변수를 합쳐 의미있는 토큰으로 만든다.
    reference:CX.cpp
    */
}