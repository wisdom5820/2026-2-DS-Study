#include <iostream>
#include <string>

#define T(x) std::to_string((x))<<" "
int main(){
    float x=45.2;
    double y=341.11;
    long double z=351231.22;

    std::cout<<T(x)<<T(y)<<T(z);
    /*
    부동 소수점 연산에서 소수점 아래 6번째자리까지 나타낸다!
    reference:String 310 - to_string( ) for numbers.cpp
    */
}