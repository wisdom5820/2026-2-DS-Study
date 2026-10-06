#include <bits/stdc++.h>
#define word int

auto foo(int x)->bool{
    return true;
}

template <typename T, typename C>
auto bar(T t, C c)->decltype(begin(t), c){
    return c;
}

int main(){
    word a=0;

    foo(a);
    /*
    auto와 ->을 이용한 문법 ->은 포인터로 멤버에 접근하는 것이 아니라 반환형을 뒤에 제시한다. template문과 유용하게 사용할 수 잇는데
    특정 type에서만 유효한 연산을 활용하여, template로 유추하는 타입의 형태를 제한할 수 있다.
    예를 들어 template의 타입 T에 해당하는 매개변수에 iterator 순회가 가능한 값만을 이용하고 싶다면,
    */
    std::vector<word> v0;
    std::array<word, 5> v1;
    std::deque<word> v2;
    std::stack<word> v3;
    
    for(word i=0; i<5; ++i){
        v0.push_back(i);
        v1.at(i)=i;
        v2.push_back(i);
        v3.push(i);
    }

    bar(v0, a);
    bar(v1, a);
    bar(v2, a);
    //bar(v3, a); syntax error begin 연산이 불가능하기에 ,연산을 통과하지 못했다.

    /*
    reference:Template 180 - template for vector.cpp
    */
}