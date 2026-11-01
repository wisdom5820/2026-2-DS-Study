/*

1. 사용한 AI (model 까지) :
    Chat GPT 6 Astra

2. 과제에서 활용한 부분 :
    100만개와 0.2초 내에 끝내기 위해 어떤 형식으로 자료구조를 구현해야 할 지에 대해 확인

3. 어떤 도움이 필요했는지 :
    list를 이용한 경우에는 시간복잡도가 O(N^2)가 나온다고 하여 어떻게 해야할 지에 대해 물어보았습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    펜윅 트리라는 것을 활용해서 배열로 구현하지만 생존자를 구간 별로 관리하여 최종 winner를 구할 수 있습니다.

*/

#include<bits/stdc++.h>

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
    if (q < p) {cerr << "\nBound p,q error"; exit(1); }
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


class Fenwick {
    int n;
    vector<int> tree;

public:
    explicit Fenwick(int n) : n(n), tree(n + 1) {
        // 모든 자리가 생존 상태인 경우의 초기 트리
        for (int i = 1; i <= n; ++i)
            tree[i] = i & -i;
    }

    // 원래 자리 i의 학생을 삭제 (1-based)
    void remove(int i) {
        while (i <= n) {
            --tree[i];
            i += i & -i;
        }
    }

    // 생존자 중 k번째 학생의 원래 자리 반환 (1-based)
    int kth(int k) const {
        int idx = 0;
        int step = 1;

        while (step <= n / 2)
            step *= 2;

        for (; step > 0; step /= 2) {
            int next = idx + step;

            if (next <= n && tree[next] < k) {
                idx = next;
                k -= tree[next];
            }
        }

        return idx + 1;
    }
};

void winner(const vector<int>& Guest) {
    int n = (int)Guest.size();
    Fenwick alive(n);

    int pos = 0;             // 현재 생존자 중 기준 순번 (0-based)
    int jump = Guest[0];

    for (int remaining = n; remaining > 1; --remaining) {
        // 원형 이동 후 탈락자의 순번
        pos = (pos + jump) % remaining;

        // 생존자 순번을 원래 자리로 변환
        int seat = alive.kth(pos + 1);

        jump = Guest[seat - 1];
        alive.remove(seat);

        // 삭제하면 다음 학생이 같은 순번으로 당겨진다.
        // 마지막 순번을 삭제했다면 처음으로 돌아간다.
        pos %= remaining - 1;
    }

    int lastSeat = alive.kth(1);
    cout << Guest[lastSeat - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, q, key;
    cin >> p >> q >> key;

    vector<int> Guest = get_seat(p, q, key);
    winner(Guest);
}
