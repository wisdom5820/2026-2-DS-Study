#include <iostream>
#include <vector>
#include <iterator>

int main(){
    std::vector<int> v{1,2,3,4,5,6};
    std::vector<int>::const_iterator it0;
    std::vector<int>::iterator it1;

    it0=v.begin();
    
    std::cout<<*it0<<'\n';

    it0=v.end()-1;
    it1=v.end()-1;

    std::cout<<*it0<<'\n';

    *it1=3;

    std::cout<<*it0;

    //*it0=56; impossible

    /*
    const_it에서 허용되지 않는 연산은 const값 참조를 통한 원본 번형이다.
    reference:STL Const 210 - const_iterator.cpp
    */
}
