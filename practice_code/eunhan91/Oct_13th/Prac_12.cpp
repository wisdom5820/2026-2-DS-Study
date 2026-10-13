#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v1{3,21,4,32,5};
    auto it_begin=v1.begin(), it_end=v1.end();

    auto pend=remove(it_begin, it_end, 3);

    cout<<pend-it_begin; //교수님께서 우려하신 오류 

    vector<int> v2{3,21,4,32,5};

    cout<<"\n>previous size:"<<v2.size();
    auto pend2=remove(v2.begin(), v2.end(), 3);//올바른 사용방법
    cout<<"\n>later size:"<<v2.size();

    v2.resize(pend2-v2.begin());
    cout<<"\n>size that I want to:"<<v2.size();

    /*
    Error가 발생하지 않는다 교수님이 말씀하신 begin과 end가 변경되는 오류는 
    원소의 크기가 변형되는 "erase"와 같은 연산을 사용하였을때 발생한다.
    remove는 실제로 값을 지우는 것이 아닌 위치 관계를 변형 시키는 연산이라 위 v1에 적용한 방식이 유효하고
    erase는 v1에 적용한 방식이 유효하지 않은 경우가 대부분이다.
    */
}