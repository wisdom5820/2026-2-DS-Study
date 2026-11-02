/*
- 사용한 AI: ChatGPT

- 과제에서 활용한 부분: 원형 리스트 순회

- 어떤 도움이 필요했는지: 
    list의 advance(), distance()를 이용한 원형 순회에서 시간초과가 발생하여 효율적인 해결방법이 필요했다.

- AI를 통해 추가, 개선한 부분: 
    Fenwick Tree를 활용해 생존자의 순위를 관리하고, update()와 find()로 이동 및 삭제를 처리하도록 개선했다. 
*/

#include <bits/stdc++.h>
using namespace std;

class LocalRandom {
    private: uint32_t state;
    public:
        explicit LocalRandom(int key) {
            state = static_cast<uint32_t>(key);
        }
        uint32_t next() {
            state = state * 1664525u + 1013904223u;
            return state;
        }
};

vector<int> get_seat(int p, int q, int key) {
    if (q < p) { cerr << "\nBound p,q error"; exit(1); }

    vector<int> Guest;
    for (int i = p; i <= q; i++) Guest.push_back(i);

    LocalRandom rng(key);

    // Fisher-Yates random shuffle
    for (int i = (int)Guest.size() - 1; i > 0; i--) {
        int j = rng.next() % (i + 1);
        swap(Guest[i], Guest[j]);
    }
    return Guest;
}

vector<int> tree;
int sizeN;

void update(int idx, int diff) {
    while(idx <= sizeN) {
        tree[idx] += diff;
        idx += idx & -idx;
    }
}

int find(int k) {
    int idx = 0;
    int bit = 1;

    while(bit <= sizeN / 2) bit <<= 1;
    while(bit > 0) {
        int next = idx + bit;

        if(next <= sizeN && tree[next] < k) {
            idx = next;
            k -= tree[next];
        }
        bit >>= 1;
    }
    return idx + 1;
}

int main() {
    int p, q, key;
    cin >> p >> q >> key;

    vector<int> Guest = get_seat(p, q, key);
    
    sizeN = Guest.size();
    tree.resize(sizeN + 1);

    for(int i = 1; i <= sizeN; i++) tree[i] = i & -i;

    int N = sizeN;
    int jump = Guest[0];

    int currentRank = 0;

    while(N > 1) {
        int turn = jump % N;

        int targetRank = (currentRank + turn) % N;
        int seat = find(targetRank + 1);
        jump = Guest[seat - 1];
        update(seat, -1);
        N--;
        currentRank = targetRank % N;
    }

    int x = find(1);
    cout << Guest[x - 1];
}