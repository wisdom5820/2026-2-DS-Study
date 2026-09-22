#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
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

        // mid 높이로 잘랐을 때 얻을 수 있는 나무 총길이 계산
        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                sum += (trees[i] - mid);
            }
        }

        // 가져갈 수 있는 나무의 길이가 M 이상이면 높이를 더 높여본다.
        if (sum >= M) {
            ans = mid;      // 조건 만족하므로 일단 정답 후보 저장
            low = mid + 1;  // 더 높은 H 탐색
        } else {
            high = mid - 1; // M 미만이면 절단기 높이를 낮춰야 함
        }
    }

    cout << ans << "\n";

    return 0;
}
