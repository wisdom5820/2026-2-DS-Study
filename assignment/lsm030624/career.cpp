/*
1. 사용한 AI (model 까지) :
    Chat GPT 6 Astra

2. 과제에서 활용한 부분 :
    함수 구현에 있어서 활용을 하였습니다.

3. 어떤 도움이 필요했는지 :
    먼저 Guest라는 struct를 만들어서 3가지 입력을 받고, 이를 연산자 오버로딩을 활용하는 것의 조건을 구현하는 것에 도움을 받았습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    간단한 if else의 경우에는 삼항연산자로 처리할 수 있게 하였습니다.
*/

#include <bits/stdc++.h>
using namespace std;

struct Guest {
    int entered, id, remaining;

    bool operator<(const Guest& other) const {
        if (remaining != other.remaining)
            return remaining < other.remaining;
        return entered > other.entered;
    }
};

vector<Guest> read_guests() {
    int n;
    cin >> n;
    vector<Guest> guests(n);
    for (Guest& g : guests)
        cin >> g.entered >> g.id >> g.remaining;

    return guests;
} // end of read_guests()

void run_center(const vector<Guest>& guests) {
    priority_queue<Guest> waiting;
    int now = 30;
    int next = 0;
    while (next < guests.size() || !waiting.empty()) {
        if (waiting.empty())
            now = max(now, guests[next].entered);

        while (next < guests.size() && guests[next].entered <= now)
            waiting.push(guests[next++]);

        Guest g = waiting.top();
        waiting.pop();
        int duration = g.remaining <= 10 ? g.remaining : g.remaining / 2;
        now += duration;
        g.remaining -= duration;

        if (g.remaining == 0) {
            cout << g.id << '\n';
        }
        else {
            g.entered = now;
            waiting.push(g);
        }
    }
} // end of run_center()

int main() {
    vector<Guest> guests = read_guests();
    run_center(guests);
} // end of main()
