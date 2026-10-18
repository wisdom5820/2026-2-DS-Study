#include <iostream>
#include <vector>

int main(){
    std::vector<int> v{1,2,3,4,5,6,7,8}; //capacity==8
    std::vector<int>::iterator it1, it2, it3;

    it1=v.begin();
    it2=v.begin()+(v.end()-v.begin())/2;
    it3=v.end();

    v.push_back(9); //메모리 재할당이 일어나 1 2 3모두 무효화 만약 v의 capacity가 9였다면 무효화 x

    it1=v.begin();
    it2=v.begin()+(v.end()-v.begin())/2;
    it3=v.end();

    v.erase(it2); //it2 이후의 it3와 it2만 무효화

    std::cout<<*it1<<'\n';

    it1=v.begin();
    it2=v.begin()+(v.end()-v.begin())/2;
    it3=v.end();

    v.insert(it2, 0); //it2와 이후 it3을 무효화

    std::cout<<*it1<<'\n';

    /*
    reference:iterator 330~350
    */
}