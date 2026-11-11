#include <bits/stdc++.h>
using namespace std;

//priority_queue<자료형, 구현체, 비교 연산자>
//default = 구현체 : vector<자료형>, 비교 연산자 : less<자료형>(max heap)  
int main(){
  int thedata[] = { 145, 234, 112, 88, 56, 27, 571, 150, 62};
  priority_queue<int> pq1 (thedata, thedata+8);
  // priority_queue<int> pq2 { 145, 234, 112, 88, 556, 327, 571, 150, 62}; //초기화 불가능. // priority_queue에는 initialzation이 따로 없다.
}
// push or emplace로 입력 가능
// STL PQ에는 begin( ), end( )가 없다.
