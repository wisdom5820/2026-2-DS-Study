/*
1. 사용한 AI (model 까지) :
    Gemini 3.6 Flash, Chat GPT 5.6 Luna

2. 과제에서 활용한 부분 :
    함수 단위로 분리하지 않고 풀었지만 이번에는 main()의 driver routine을 해 보고자 하였고, 어떻게 해야 접근이 가능할 지에 대해 사용하였습니다.

3. 어떤 도움이 필요했는지 :
    함수 단위로 분리를 하였으나 주어진 토큰 개수를 넘어서 토큰 수를 줄이는 것이 필요했습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    find_min_index() 함수의 경우, 내장함수를 사용하여 구할 수 있었습니다.
    re_allocation() 함수의 경우에는 굳이 return값을 받지 않아도 값이 수정됨을 알 수 있었고, 이는 매개변수로 reference 할 경우에도 마찬가지임을 알 수 있었습니다.
    처음에는 지역변수로서 접근을 할려 했으나, 함수 뿐만 아니라 매개변수가 너무 많았습니다.
    따라서 가장 함수에 많이 들어가는 매개변수만 따로 전역변수로써 선언하고, 나머지는 최대한 지역변수로써 해결하고자 하였습니다.
    또한 출력에서 빈 경우에는 0을 출력할 수 있게 수정하였습니다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<stack<int>> stacks;
vector<int> heights;
int max_index, min_index;

void input_stack(int N) { // vector<stack<int>>& stacks, vector<int>& heights, int N
    while (N--) {
        int height;
        cin >> height;
        heights.push_back(height);

        stack<int> stk;
        while (height--) {
            int ID;
            cin >> ID;
            stk.push(ID);
        }
        stacks.push_back(stk);
    }
} // end of input_stack()

pair<int, int> max_min_height_calculation() { // vector<int> heights
    return {*max_element(heights.begin(), heights.end()), *min_element(heights.begin(), heights.end())};
} // end of max_min_height_calculation()

int find_max_index(int max_height) { // vector<stack<int>> stacks, vector<int> heights, int max_height
    int index = 0;
    int max_weight = 0;

    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] == max_height && stacks[i].top() > max_weight) {
            max_weight = stacks[i].top();
            index = i;
        }
    }
    return index;
} // end of find_max_index()

int find_min_index(int min_height) { // vector<int> heights, int min_height
    return find(heights.begin(), heights.end(), min_height) - heights.begin();
} // end of find_min_index()

void re_allocation() { // vector<stack<int>>& stacks, vector<int>& heights, int max_index, int min_index
    int ID = stacks[max_index].top();
    stacks[max_index].pop();
    stacks[min_index].push(ID);
    heights[max_index]--;
    heights[min_index]++;
} // end of re_allocation()

void print() { // vector<stack<int>>& stacks
    for (auto& stk : stacks) {
        if (stk.empty())
            cout << 0;
        else {
            vector<int> temp;
            while (!stk.empty()) {
                temp.push_back(stk.top());
                stk.pop();
            }
            for (auto it = temp.rbegin(); it != temp.rend(); it++)
                cout << *it << ' ';
        }
        cout << '\n';
    }
} // end of print()

int main() {
    int N;
    cin >> N;

    input_stack(N);

    auto [max_height, min_height] = max_min_height_calculation();

    while (max_height - min_height > 1) {
        max_index = find_max_index(max_height);
        min_index = find_min_index(min_height);

        re_allocation();

        tie(max_height, min_height) = max_min_height_calculation();
    }

    print();
} // end of main()
