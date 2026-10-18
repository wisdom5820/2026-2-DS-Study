#include <iostream>
#include <array>
#include <exception>
#include <stdexcept>

int main(){
    std::array<int, 7> arr{0,1,2,3,4,5,6};

    //arr[7] 은 에러를 일으킨다.
    try{ 
        arr.at(564);// 에러가 발생한다.
    }

    catch(std::out_of_range & e){
        std::cout<<e.what();
    }//항상 중괄호로 둘러싸야한다.

    //referecne:Array_More 140 중요 Try in array.at( ).cpp
    return 0;
}