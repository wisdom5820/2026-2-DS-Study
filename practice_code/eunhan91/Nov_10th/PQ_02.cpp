#include <queue>
#include <string>

using namespace std;

struct compare
{
    bool operator() (string a, string b){
        return a.front()>b.front();
    }
};

int main(){
    priority_queue<string, vector<string>, compare> my_PQ; //함수 객체 형식이 와야하는 곳. 임의로 함수 객체를 만드는 방법은 struct

    compare cmp;// < 내부적으로 이와 같이 함수 객체를 만들어 비교가 필요할 때 호출하여 사용.

    /*
    reference:PriorityQ- 150 - Compare.cpp
    */  
}