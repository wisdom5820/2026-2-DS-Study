#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    int x; // 입력값
    long long total = 0; // int로 하니까 overflow -> long long으로 수정
    stack<int> s;
    bool cancelled = false;
    
    /* -- 입력 -- */
    while(cin >> x, x != -1) { 
        if(x == 0) { 
            if(s.empty()) {
                cancelled = true; 
                continue; // cancelled라도 입력은 계속 받아야 하니까 continue 처리
            }

            total -= s.top(); // 스택 입력과 total 값 계산 같이 
            s.pop();
        } else {
            s.push(x);
            total += x; 
        }
    }

    /* -- 결과 -- */
    if(cancelled) { // cancelled면 먼저 끝내기
        cout << "say: There were too many cancellations.\n";
        return 0;
    }

    if(s.size() >= N) { 
        if(s.size() > N) cout << "think: oh yes!!!\n";
        cout << total;
    } else { 
        cout << "say: It`s less than my working days\n";
    }

    return 0;
}