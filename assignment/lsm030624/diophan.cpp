/*

1. 사용한 AI (model 까지) :
    GPT-6.1 Sol

2. 과제에서 활용한 부분 :
    단순한 loop문이 아닌 다른 접근법에 대한 힌트를 얻고자 했습니다.

3. 어떤 도움이 필요했는지 :
    처음에는 재귀적으로 풀고자 생각하였고 어느정도의 구현은 완성하였지만 군데군데 논리적 결함이 있고, 시간 초과 문제를 해결하고자 사용하였습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    원래는 재귀함수를 이용하여 풀려고 하였지만 최악의 경우, 1초를 초과할 수 있다고 하여 찾아보니 메모이제이션이라는 방법이 있었습니다.
    조건이 양의 정수이므로 이를 음이 아닌 정수로 바꾸는 과정에서 결과값이 0 이상은 고려하지 않아도 되고, 음수일 때만 바로 0을 리턴하는 예외처리에 대해 알게되었습니다.
    또한 처음에 계수들을 내림차순으로 정렬하였는데 이 때, 마지막 계수에 대해서 초과시 return 처리만 하였지만 남은 값이 0인지 아닌지 확인하는 절차를 통해
    solutions의 개수를 파악할 수 있었습니다.

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 19991;

int N, R;
vector<int> coef;
vector<vector<int>> memo;

void input(){
    cin >> N;
    coef.resize(N);

    for (int& c : coef)
        cin >> c;

    cin >> R;

    // 각 변수를 최소 한 번씩 사용하는 경우 가정 (음이 아닌 정수)
    for (int c : coef)
        R -= c;

    if (R < 0) {
        cout << 0;
        exit(0);
    }

    sort(coef.begin(), coef.end(), greater<int>());

    memo.assign(N, vector<int>(R + 1, -1));
} // end of input()

int recur(int index, int rem) {
    if (rem == 0) // 정확히 떨어질 때
        return 1;

    if (index == N) // 끝까지 확인해도 떨어지지 않을 때
        return 0;

    int& result = memo[index][rem];

    if (result != -1) // 이미 계산된 값이라면 넘어가기
        return result;

    // 현재 계수를 추가로 사용하지 않고 다음 변수로 이동
    result = recur(index + 1, rem);

    // 현재 계수를 한 번만 추가로 사용
    if (rem >= coef[index])
        result = (result + recur(index, rem - coef[index])) % MOD;

    return result;
} // end of recur()

void output(){
    cout << recur(0, R);
} // end of output()

int main() {
    input();
    recur(0, R);
    output();
} // end of main()
