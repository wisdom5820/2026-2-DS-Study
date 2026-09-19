#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;

    int openP = 0, closeP = 0; // 여는 괄호, 닫는 괄호
    int mod = 0; // 수정 횟수

    for(int i = 0; i < N; i++) {
        char p;
        cin >> p;

        if(p == '(') openP++;
        else         closeP++;

        if(closeP > openP) {
            mod++;
            openP++;
            closeP--;
        }
    }

    cout << mod;

    return 0;
}

// container 없이 푸는 방법 밖에 떠오르지 않는다..
// stack이 왜 필요한 걸까