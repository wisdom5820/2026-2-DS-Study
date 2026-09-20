#include <iostream>
#include <unordered_map> // find 가 O(1)
using namespace std;

int main() {
    int N, i;
    cin >> N;

    unordered_map<int, int> m; // first : 현재 위치, second : 이동 거리
    for(i = 0; i < N; i++) {
        int a, b;
        char c;
        cin >> a >> c >> b;

        if(c == 'R') m[a] = b;
        else         m[a] = -b;
    }

    int myloc;
    cin >> myloc;

    for(i = 0; i < N; i++) 
        myloc += m[myloc];
    

    cout << myloc;
    return 0;
}