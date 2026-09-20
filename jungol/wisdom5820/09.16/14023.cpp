#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N, i;
    cin >> N; // 메뉴 개수

    unordered_map<long long, int> menu;  // first : price, second : cnt

    long long total = 0;
    long long offset = 0; // inflation -> 누적 증가량을 저장하기 위한 변수

    for(i = 0; i < N; i++) {
        int price;
        cin >> price;

        menu[price]++;
        total += price; // total 계산
    }
    
    int k;
    cin >> k;

    while(k--) {
        string order;
        cin >> order;

        if(order == "INFLATION") {
            long long inflation;
            cin >> inflation;

            /* INFLATION 때마다 unordered_map 전체를 순회하기 때문에 시간 초과남 */
            // unordered_map<int, int> newMap;
            // for(auto& [price, cnt] : menu) { 
            //     newMap[price + inflation] = cnt;

            //     total += inflation * cnt; 
            // }
            
            // menu.swap(newMap);


            /* 누적 증가량을 저장 */
            offset += inflation;
            total += inflation * N; // 메뉴 N개의 가격이 inflation만큼 증가
        }

        else if(order == "SET") {
            long long original, change;
            cin >> original >> change;

            // if(original != change && menu.find(original) != menu.end()) {
            //     menu[change] += menu[original]; 

            //     total += (change - original) * menu[original]; 

            //     menu.erase(original);
            // }
            
            long long originalKey = original - offset;
            long long changeKey = change - offset;

            auto it = menu.find(originalKey); // iterator를 사용하여 중복 탐색을 줄임
            
            if(original != change && it != menu.end()) {
                int cnt = it->second;
                
                // unordered_map의 삽입이 rehash를 일으키면 기존 iterator가 무효화될 수 있음
                // 기존 원소를 지우고 나서 새 key를 추가하는 방식이 더 안전함
                menu.erase(it); 
                menu[changeKey] += cnt;

                total += (change - original) * cnt;

                // menu.erase(it);
            }
        }

        // total 출력
        cout << total << "\n";
    }

    return 0;
}