/*

1. 사용한 AI (model 까지) :
    Gemini 3.6 Flash

2. 과제에서 활용한 부분 :
    vector<vector<int>> 자료형 초기값 설정

3. 어떤 도움이 필요했는지 :
    처음에는 vector<vector<int>> v의 크기를 N으로 가정하고 했으나, 인덱스 접근이 불가능하거나, 어려워서 어떻게 시작해야할 지 도움이 필요했습니다.


4. AI 제시 코드에서 추가, 개선한 부분 :
    처음에는 vector<vector<int>> v의 크기를 N으로 가정하고 했으나, 인덱스 접근이 어려워서 결국은 처음에는 비어있는 상태로 시작하기로 하였습니다.
    이후 vector의 lower_bound()를 사용하여, no보다 작은 지점을 찾아서 insert를 하고, 이후에는 resize(k)를 이용하여 한 번에 vector의 크기를 k로 정리할 수 있었습니다.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;

    vector<vector<int>> v;

    while (N--) {
        char pm;
        int no;
        cin >> pm >> no;

        if (pm == '+') {
            if (v.empty()) {
                v.push_back({no});
                continue;
            }

            int target = -1;
            for (int i = 0; i < v.size(); ++i) {
                if (i < v.size() - 1 && v[i].back() < no && v[i+1].front() > no){
                    target = i;
                    break;
                }
                else if (no <= v[i].back() || i == v.size() - 1) {
                    target = i;
                    break;
                }
            }

            auto it = lower_bound(v[target].begin(), v[target].end(), no);
            v[target].insert(it, no);

            if (v[target].size() == 2 * k) {
                vector<int> right_half(v[target].begin() + k, v[target].end());
                v[target].resize(k);
                v.insert(v.begin() + target + 1, right_half);
            }
        } else if (pm == '-') {
            for (auto vec = v.begin(); vec != v.end(); vec++) {
                auto it = find(vec->begin(), vec->end(), no);
                if (it != vec->end()) {
                    vec->erase(it);
                    if (vec->empty()){
                        v.erase(vec);
                    }
                    break;
                }
            }
        }
    }

    for (const auto& vec : v) {
        if (!vec.empty()) {
            cout << vec.front() << "\n";
        }
    }

}
