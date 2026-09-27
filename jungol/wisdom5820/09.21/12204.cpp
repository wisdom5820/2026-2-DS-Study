#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 원하는 출고 순서
    vector<int> target(N);
    for (int i = 0; i < N; i++)
        cin >> target[i];

    // order[x] = x번 공룡이 몇 번째로 출고되어야 하는지
    vector<int> order(N + 1);
    for (int i = 0; i < N; i++)
        order[target[i]] = i;

    queue<int> Q1, Q2;
    vector<string> result;

    int nextIn = 1;  // 다음에 들어올 공룡
    int outIdx = 0;  // 다음에 출고해야 하는 위치

    bool possible = true;

    while (outIdx < N) {
        int outnow = target[outIdx];

        // 현재 출고할 공룡이 Q1 맨 앞에 있음
        if (!Q1.empty() && Q1.front() == outnow) {
            result.push_back("OUT 1");
            Q1.pop();
            outIdx++;
        }

        // 현재 출고할 공룡이 Q2 맨 앞에 있음
        else if (!Q2.empty() && Q2.front() == outnow) {
            result.push_back("OUT 2");
            Q2.pop();
            outIdx++;
        }

        // 아직 큐에 없다면 새로운 공룡을 IN
        else {
            if (nextIn > N) {
                possible = false;
                break;
            }

            bool canQ1 = Q1.empty() || order[Q1.back()] < order[nextIn];
            bool canQ2 = Q2.empty() || order[Q2.back()] < order[nextIn];

            int selected = 0;
            if (canQ1 && canQ2) { // 둘 다 가능
                if (Q1.empty()) {
                    selected = 1;
                }
                else if (Q2.empty()) {
                    selected = 2;
                }
                else if (order[Q1.back()] > order[Q2.back()]) {
                    selected = 1;
                }
                else {
                    selected = 2;
                }
            } else if (canQ1) { // Q1만 가능
                selected = 1;
            } else if (canQ2) { // Q2만 가능
                selected = 2;
            } else { // 둘 다 불가능
                possible = false;
                break;
            }

            if (selected == 1) {
                Q1.push(nextIn);
                result.push_back("IN 1");
            }
            else {
                Q2.push(nextIn);
                result.push_back("IN 2");
            }

            nextIn++;
        }
    }

    if (!possible) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << result.size() << '\n';

        for (const string& str : result)
            cout << str << '\n';
    }

    return 0;
}