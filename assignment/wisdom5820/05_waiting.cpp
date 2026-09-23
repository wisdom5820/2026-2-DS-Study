/*
 * 사용한 AI : ChatGPT
 * 과제에서 활용한 부분 : vector 의 주요 멤버 함수 활용 방법을 질문, 초기 접근 방법 설계, 오류 점검
 * 어떤 도움이 필요했는지 : vector의 insert, erase, iterator 사용 방법을 질문하여 참고함
 *                       빈 의자 삭제 및 iterator 무효화와 같은 구현 과정의 오류를 점검하는 데 도움을 받음
 * AI를 통해 추가, 개선한 부분 : AI가 제시한 힌트를 바탕으로 마지막 의자 처리, 의자 분할, 고객 퇴장 및 빈 의자 삭제 로직을 직접 구현하고 수정함
 */

#include <bits/stdc++.h> 
using namespace std;

int main() {
    int N, k;
    cin >> N >> k;

    vector<vector<int>> room;

    while(N--) {
        char transaction; // +, -
        int x; // 대기번호
        cin >> transaction >> x;

        switch(transaction) {
            case '+':
                if(room.empty()) room.push_back({x}); // (예외) room이 비어있을 때
                
                else {
                    vector<vector<int>>::iterator chair;

                    for(auto it = room.begin(); it != room.end(); it++) { 
                        if(it == room.end() - 1 || x < (it + 1)->front()) { // 다음 의자의 첫 번째 원소보다 작거나 마지막 의자인 경우
                            it->push_back(x); // 조건에 부합하면 push_back
                            sort(it->begin(), it->end()); 
                            chair = it; // iterator 저장

                            break;
                        }
                    }

                    if(chair->size() == 2*k) { // 의자가 꽉 차면
                        vector<int> temp(chair->begin() + k, chair->end());  // 의자 후반부 복사
                        
                        chair->resize(k); // 반으로 쪼개기

                        room.insert(chair + 1, temp); // 다음 의자 insert
                    }
                }
                
                break;

            case '-':

                for(auto it = room.begin(); it != room.end(); it++) {
                    auto chair = find(it->begin(), it->end(), x); 

                    if(chair != it->end()) { // 찾았으면
                        it->erase(chair); // 의자에서 지우기

                        if(it->empty()) room.erase(it); // 의자가 비었으면 의자 자체를 지우기

                        break;
                    }
                }
                
                break;
        }
    }

    // 출력
    for(auto& v : room) cout << v.front() << '\n';
    return 0;
}