#include <iostream>
#include <vector>

int main(){
    std::vector<int> v1{1,2,3,4,5,6,7,8,9,10};//size==10
    std::vector<int> v2{1,2,3,4};//size==4

    std::copy(v1.begin()+5, v1.end(), v2.begin()); //v1에서 복사하는 원소의 개수 5개 v2의 사이즈 4 즉 복사하려는 값이 저장할 메모리보다 크다. 이미 UB를 진행한 셈

    for(auto w:v2)
        std::cout<<w<<" ";//겉으로는 6 7 8 9가 출력될 수 있지만, 이미 범위를 벗어나 썼으므로 UB이다. 세그먼트 폴트 발생 여부는 보장되지 않는다.
    //reference:Vector More 280- Generic copy( ) for vec.cpp
}