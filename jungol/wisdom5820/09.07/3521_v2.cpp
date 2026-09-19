#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력
    vector<int> coin = {1, 2, 4, 8, 16}; // 추의 무게
    vector<int> count(5); // 추의 개수
    for(auto& c : count) cin >> c;

    int N;
    cin >> N;

    // greedy algorithm
    // for문 역순, 나눗셈으로 처리
    int use = 0;
    for(int i = 4; i >= 0; i--) {
        int m = min(N/coin[i], count[i]);

        use += m;
        N -= coin[i] * m;

        if(N <= 0) break;
    }

    // 결과 출력
    if(N > 0) cout << "impossible";
    else      cout << use;    
    
    return 0;
}