/*
1. 사용한 AI (model 까지) :
    Gemini 3.6 Flash, Chat GPT 6 Astra

2. 과제에서 활용한 부분 :
    토큰 수 줄이기 및 시간 초과 문제를 해결하고자 단순히 모든 함수들을 호출하는 방식이 아닌 다른 방식에 대해 알고자 활용하였습니다.

3. 어떤 도움이 필요했는지 :
    Func_range에 함수 이름 및 함수의 총 호출 횟수를 저장하는 아이디어를 얻었고, Active, Done, Computed라는 map 변수를 통해
    시간 초과를 해결하고자 하였습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    Func_range에 함수 이름 및 함수별 호출 횟수를 저장하였고, map<string, bool> Active, Done, Computed를 이용하여 Deadlock을
    판별 할 수 있었습니다.

*/
#include<bits/stdc++.h>
using namespace std;
#define START "M"
typedef long long Dlong;

stack<string> Funcall;
map<string, vector<string>> Func_list;
map<string, Dlong> Func_range;
map<string, bool> Active, Done, Computed;
Dlong N, k1, k2, max_index;


void input(){
    cin >> N >> k1 >> k2;
    for (Dlong i = 0; i < N; i++) {
        string func_name, statement;
        cin >> func_name;
        Func_range[func_name] = 0;
        while (cin >> statement) {
            Func_list[func_name].push_back(statement);

            if (statement == "$") break;
        }
    }
} // end of input()

bool recur(const string& func_name) {
    if (Done[func_name]) return false;

    Active[func_name] = true;

    for (const string& s : Func_list[func_name]) {
        if (s == "$") break;

        if (s >= "A" && s <= "Z") {
            if (Active[s]) return true;
            if (recur(s)) return true;
        }
    }

    Active[func_name] = false;
    Done[func_name] = true;
    return false;
} // end of recur()

Dlong compute(const string& func_name) {
    if (Computed[func_name])
        return Func_range[func_name];

    Dlong length = 0;

    for (const string& s : Func_list[func_name]) {
        if (s == "$") break;

        if (s >= "A" && s <= "Z")
            length += compute(s);
        else
            length++;
    }

    Computed[func_name] = true;
    return Func_range[func_name] = max_index = length;
} // end of compute()

bool deadlock() {
    bool result = recur(START);

    for (auto& [name, range] : Func_range)
        Func_list[name].pop_back();

    if (result) cout << "DEADLOCK\n";
    return result;
} // end of deadlock()

string find_statement(Dlong prev_index, Dlong find_index, const string& func_name) {
    for (const string& s : Func_list[func_name]) {
        if (s == "$") break;

        else if (s >= "A" && s <= "Z") {
            if (find_index - prev_index <= Func_range[s])
                return find_statement(prev_index, find_index, s);
            prev_index += Func_range[s];
        } else {
            if (++prev_index == find_index)
                return func_name + "-" + s;
        }
    }

    return "NONE";
} // end of find_statement()

void output() {
    for (Dlong k : {k1, k2})
        cout << find_statement(0, k < 0 ? k + max_index + 1 : k, "M") << '\n';
} // end of output()

int main() {
    input();

    if (deadlock()) return 0;

    compute(START);

    output();
} // end of main()
