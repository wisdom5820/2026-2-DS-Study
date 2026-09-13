#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // AI - gemini 사용함
    // [AI] std::map은 Key를 기준으로 자동 오름차순 정렬됨
    map<int, string> bidding;
    map<int, int> count;

    for(int i = 0; i < N; i++) {
        string name;
        int price;
        cin >> name >> price;
        bidding[price] = name; 
        count[price]++;
    }
    
    // [AI] map을 탐색할 때는 iterator(역방향은 rbegin/rend)를 사용함
    for(auto it = count.rbegin(); it != count.rend(); ++it) { 
        if(it->second == 1) {
            cout << bidding[it->first];
            return 0;
        }
    }
    cout << "NONE";

    return 0;
}