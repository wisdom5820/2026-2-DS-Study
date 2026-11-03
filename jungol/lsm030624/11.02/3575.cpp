#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node* left = nullptr;
    node* right = nullptr;
};

int P, NS, T;

void dfs(node* root) {
    stack<node*> s;
    vector<int> parent(P + 1, 0);

    s.push(root);

    while (!s.empty()) {
        node* f = s.top();
        s.pop();

        if (f->value == T) {
            vector<int> path;

            // 보물에서 입구까지 부모를 따라가기
            for (int cur = T; cur != 0; cur = parent[cur]) {
                path.push_back(cur);
            }

            reverse(path.begin(), path.end());

            cout << path.size() << '\n';
            for (int x : path) {
                cout << x << '\n';
            }

            return;
        }

        if (f->right != nullptr) {
            parent[f->right->value] = f->value;
            s.push(f->right);
        }

        if (f->left != nullptr) {
            parent[f->left->value] = f->value;
            s.push(f->left);
        }
    }
}

int main() {
    cin >> P >> NS >> T;

    // 노드 번호와 인덱스를 일치시킴
    vector<node> nodes(P + 1);

    for (int i = 1; i <= P; i++) {
        nodes[i].value = i;
    }

    for (int i = 0; i < NS; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        nodes[a].left = &nodes[b];
        nodes[a].right = &nodes[c];
    }

    dfs(&nodes[1]);
}
