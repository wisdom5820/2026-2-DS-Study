#include <deque>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

void foo(priority_queue<int> x){
    cout<<"noting";
}

int main(){
    priority_queue<int, vector<int>, less<int>> PQ0; //default
    priority_queue<int, vector<int>, greater<int>> PQ1;
    priority_queue<int, deque<int>, less<int>> PQ2;
    priority_queue<int, deque<int>, greater<int>> PQ3;
    //총 네가지 구현이 가능하다.

    foo(PQ0);//foo(PQ1), foo(PQ2), foo(PQ3) 나머지 구현이 불가능하다. 비교 컨테이너와 내부 구현 컨테이너까지 같아야함.

    /*
    reference:PriorityQ- 110 - Print PQ.cpp
    */
}