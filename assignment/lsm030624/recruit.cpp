/*

1. 사용한 AI (model 까지) :
    Gemini 3.6 Flash, Chat GPT 5.6 Luna

2. 과제에서 활용한 부분 :
    POP 구현의 미완성으로 완전한 출력이 되지 않은 부분 및 각 대학별 최대 인원 수가 다른 부분을 고려 하지 못한 점과 POP 이후 총 개수가 줄어드는 것을 고려한 점

3. 어떤 도움이 필요했는지 :
    POP을 입력 받았을 때, 테스트케이스와 인원 수 차이가 나거나 실제로 출력값이 아예 다르게 나온 이유를 확인했습니다.
    처음에 접근한 방식은 아예 처음부터 끝까지를 이중 반복문으로 접근하여 구현할려했지만, 완전하게 모든 인원을 확인할 수는 없었습니다. 따라서 이 부분의 구현에 대해 도움을 받았습니다.
    그리고 POP 이후 size() 연산으로 감소된 것을 나타내야했습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    각 대학 별로 인원 수가 달라도 문제가 없을 수 있었습니다.

*/

#include <bits/stdc++.h>
using namespace std;

struct regist_info { int ID, COTE; };
map<string, vector<regist_info>> recruit_list;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) return a.second > b.second;
    
    auto get_sum = [](const string& g) {
        return accumulate(recruit_list[g].begin(), recruit_list[g].end(), 0,
                          [](int sum, const regist_info& r) { return sum + r.COTE; });
    };
    int sum_a = get_sum(a.first), sum_b = get_sum(b.first);
    return sum_a != sum_b ? sum_a > sum_b : a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, k; cin >> N >> k;

    string GRAD;
    int p, q;

    while (N-- && cin >> GRAD && GRAD != "END") {
        if (GRAD == "POP") {
            cin >> p >> q; // p = ID(시작등수), q = COTE(끝등수)
            vector<pair<string, int>> CANU;
            
            for (auto& [g, vec] : recruit_list)
                if (vec.size() >= (size_t)k) CANU.push_back({g, vec.size()});

            sort(CANU.begin(), CANU.end(), cmp);

            for (auto& [g, _] : CANU) {
                sort(recruit_list[g].begin(), recruit_list[g].end(), [](auto& a, auto& b) {
                    return a.COTE == b.COTE ? a.ID > b.ID : a.COTE > b.COTE;
                });
            }

            vector<int> popped;
            int pop_idx = 0;
            for (int out = 0; ; out++) {
                bool cand = false;
                for (auto& [g, _] : CANU) {
                    auto& reg = recruit_list[g];
                    if (out >= reg.size()) continue;
                    cand = true;
                    if (++pop_idx >= p && pop_idx <= q) popped.push_back(reg[out].ID);
                }
                if (!cand || pop_idx >= q) break;
            }

            unordered_set<int> pop_set(popped.begin(), popped.end());
            for (auto& [_, vec] : recruit_list)
                erase_if(vec, [&](auto& r) { return pop_set.count(r.ID); });

            for (int id : popped) cout << id << " ";
            cout << "\n";
        } else {
            cin >> p >> q; // p = ID, q = COTE
            recruit_list[GRAD].push_back({p, q});
        }
    }
}