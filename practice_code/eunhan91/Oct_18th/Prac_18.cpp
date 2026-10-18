#include <iostream>
#include <array>

std::array<int, 3> arr0; //생성과 동시에 초기화

#define All_out(x) for(auto w:(x)) std::cout<<w<<" "; std::cout<<'\n'
int main(){
    All_out(arr0);

    std::array<int, 3> arr1; //생성이 초기화를 보장하지 않는다.

    All_out(arr1);

    /*
    reference:Array_Tips - 160- 배열 초기값.cpp
    */
}