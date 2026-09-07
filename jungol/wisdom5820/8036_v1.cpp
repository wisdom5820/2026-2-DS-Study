#include <iostream>
#include <map>
using namespace std;

// 정답이 32비트 정수 범위를 넘을 수 있으므로 long long 자료형 사용

long long func(const map<int, int>& m) {
    long long result = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        long long k = it->second;
        result += k * (k-1) / 2; // k개 중 2개를 고르는 공식 
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    // 입력
    int n;
    cin >> n;

    map<int, int> x_count;
    map<int, int> y_count;

    for(long long i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x_count[x]++;
        y_count[y]++;
    }

    long long result = 0;
    result += func(x_count);
    result += func(y_count);

    cout << result;

    return 0;
}