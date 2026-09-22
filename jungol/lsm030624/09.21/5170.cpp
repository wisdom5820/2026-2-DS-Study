#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> trees(N);
    long long max_height = 0;

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max_height) {
            max_height = trees[i];
        }
    }

    long long low = 0;
    long long high = max_height;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sum = 0;


        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                sum += (trees[i] - mid);
            }
        }


        if (sum >= M) {
            ans = mid;     
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
