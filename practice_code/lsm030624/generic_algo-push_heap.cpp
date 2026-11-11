// range heap example
#include <iostream>     // cout
#include <algorithm>    // make_heap, pop_heap, push_heap, sort_heap
#include <vector>       // vector

using namespace std;

int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  make_heap (v.begin(),v.end());
  cout << "가장 큰 원소 : " << v.front() << '\n';

  pop_heap (v.begin(),v.end()); v.pop_back();
  cout << "pop 다음의 큰 원소 : " << v.front() << '\n';

  v.push_back(99); push_heap (v.begin(),v.end());
  cout << "max heap 다음 99 넣기: " << v.front() << '\n';

  sort_heap (v.begin(),v.end());

  cout << "정렬 후:";
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];

  cout << '\n';

  return 0;
}
