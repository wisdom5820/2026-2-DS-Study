#include <iostream>
#include <list>
#include <vector>

int main(){
    std::list<int> mylist{1,2,3,4,5};
    std::vector<int> myvector{1,2,3,4,5}; //capacity 5

    auto it1=++mylist.begin();
    auto it2=++myvector.begin();

    mylist.push_back(6); //메모리 재할당이 일어나지 않는다(capacity의 개념이 없음)
    myvector.push_back(6); //메모리 재할당 이터레이터 무효화

    std::cout<<*it1<<" "<<*it2; //처음은 정상적인 동작으로 2출력 두번째는 UB이다.

    /*
    reference:Iterator Basic  100 - ietrator Basics.cpp
    */
}