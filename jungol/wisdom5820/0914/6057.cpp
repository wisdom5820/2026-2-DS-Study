#include <iostream>
#include <queue>
using namespace std;

int main() {
    int P, N;
    cin >> P >> N;

    queue<int> pizza[P + 1];  // type 인덱스로 바로 찾을 수 있도록
    int type, price;
    long long total = 0;  // 가격 총합

    for(int i = 0; i < N; i++) {
        int cmd;
        cin >> cmd;

        switch(cmd) {
            case 0:
                cin >> type >> price;
                pizza[type].push(price);
                break;

            case 1:
                cin >> type;
                if(pizza[type].empty()) break;
                
                total += pizza[type].front();
                
                pizza[type].pop();
                break;
        }
    }

    cout << total;

    return 0;
}