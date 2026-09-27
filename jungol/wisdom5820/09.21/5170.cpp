#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;  
    long long M;
    cin >> N >> M;

    vector<int> v(N);
    for(int i = 0; i < N; i++) 
        cin >> v[i];

    long long st = 0;
    long long en = *max_element(v.begin(), v.end());
    long long answer = 0;

    while(st <= en) {
        long long mid = (st + en) / 2;

        long long sum = 0;
        
        for(int i : v) {
            if(i > mid) sum += i - mid;
        }

        if(sum >= M) {
            answer = mid;
            st = mid + 1;
        } else {
            en = mid - 1;
        }
    }
    
    cout << answer;

    return 0;
}