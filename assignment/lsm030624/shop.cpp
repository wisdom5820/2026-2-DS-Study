/*

1. 사용한 AI (model 까지) :
    Chat GPT 6 Astra

2. 과제에서 활용한 부분 :
    함수 로직 구현에 대한 수정

3. 어떤 도움이 필요했는지 :
    아이디어는 k개의 대기열에 대해 바로바로 pop을 시키고, push하는 전략으로 접근하고자 하였습니다.
    하지만 초기에는 push가 중복을 된다던지, 혹은 push가 이루어지지 않는 경우가 있었습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    기존에는 push 후 pop을 했다면, AI의 제시 코드는 pop을 먼저 한 후에 비는 queue가 존재할 때에 일일이 push하는 방식을 제안하였습니다.
    또한 exited 변수를 통해 모든 변수들이 다 pop 되었을 때에만 출력을 종료하게끔 하였습니다.

*/

#include<bits/stdc++.h>
# define MAX 20
using namespace std;

struct customer{
    string guest_id;
    int item;
};

vector<queue<customer>> Mymall;
vector<string> Exit_customer;
int N, k;

void input(){
    cin >> N >> k;
    Mymall.resize(k);
} // end of input()

void entrance_exit(int N, int k) {
    int i = 0;
    int exited = 0;
    customer guest;

    for (; i < N && i < k; ++i) {
        cin >> guest.guest_id >> guest.item;
        Mymall[i].push(guest);
    }

    while (exited < N) {
        int min_item = MAX;

        // 다음 퇴장까지 걸리는 시간
        for (const auto& q : Mymall) {
            if (!q.empty()) {
                min_item = min(min_item, q.front().item);
            }
        }

        // 모든 계산대의 남은 시간 감소
        for (auto& q : Mymall) {
            if (!q.empty()) {
                q.front().item -= min_item;
            }
        }

        // 큰 번호부터 퇴장
        for (auto it = Mymall.rbegin(); it != Mymall.rend(); ++it) {
            if (!it->empty() && it->front().item == 0) {
                Exit_customer.push_back(it->front().guest_id);
                it->pop();
                ++exited;
            }
        }

        // 작은 번호부터 입장
        for (int j = 0; j < k && i < N; ++j) {
            if (Mymall[j].empty()) {
                cin >> guest.guest_id >> guest.item;
                Mymall[j].push(guest);
                ++i;
            }
        }
    }
} // end of entrance_exit()

void output(){
    for (const string& guest_id : Exit_customer){
        cout << guest_id << "\n";
    }
} // end of output()

int main(){
    input();

    entrance_exit(N, k);

    output();
} // end of main()
