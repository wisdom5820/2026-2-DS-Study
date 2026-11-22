/*
1. 사용한 AI (model 까지) :
    Chat GPT 6 Astra

2. 과제에서 활용한 부분 :
    함수 구현에 있어서 활용을 하였습니다.

3. 어떤 도움이 필요했는지 :
    함수 로직을 구현을 할 때 재귀함수로써 구현 해야겠다고 생각했는데 어떻게 해야할 지 어려워서 도움을 받앗습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    기존에는 erase_node(), collect(), print_node() 함수를 추가하여 재귀 구현 및 비슷한 기능을 하는 함수들에 적용할 수 있게 분리하여 코드를 구성할 수 있었습니다.
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    string str;
    node* parent = nullptr;
    node* left = nullptr;
    node* right = nullptr;
    ~node() {
        delete left;
        delete right;
    }
};

node* root = nullptr;

int get_op_id(const string& op) {
    static const vector<string> ops = {"+", "-", "depth", "leaf", "quit"};
    return find(ops.begin(), ops.end(), op) - ops.begin();
} // end of get_op_id()

void insert_string() {
    string str;
    cin >> str;
    if (!root) {
        root = new node{str};
        return;
    }
    node* temp = root;
    while (true) {
        if (str == temp->str) return;
        node*& next = (str < temp->str) ? temp->left : temp->right;
        if (!next) {
            next = new node{str, temp};
            return;
        }
        temp = next;
    }
} // end of insert_string()

// Copy a replacement key until the node to erase is a leaf.
void erase_node(node* cur) {
    if (!cur->left && !cur->right) {
        node* parent = cur->parent;
        if (!parent) root = nullptr;
        else if (parent->left == cur) parent->left = nullptr;
        else parent->right = nullptr;
        delete cur;
        return;
    }

    node* replacement;
    if (cur->left) {
        replacement = cur->left;
        while (replacement->right) replacement = replacement->right;
    } else {
        replacement = cur->right;
        while (replacement->left) replacement = replacement->left;
    }
    cur->str = replacement->str;
    erase_node(replacement);
} // end of erase_node()

void delete_string() {
    string str;
    cin >> str;
    node* cur = root;
    while (cur && cur->str != str)
        cur = str < cur->str ? cur->left : cur->right;
    if (cur) erase_node(cur);
} // end of delete_string()

void collect(node* cur, int level, int k, bool leaves, vector<string>& out) {
    if (!cur) return;
    if (leaves ? (!cur->left && !cur->right) : level == k) {
        out.push_back(cur->str);
        return;
    }
    collect(cur->left, level + 1, k, leaves, out);
    collect(cur->right, level + 1, k, leaves, out);
} // end of collect()

void print_nodes(int k, bool leaves) {
    vector<string> out;
    collect(root, 1, k, leaves, out);
    if (out.empty()) cout << "NO";
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
} // end of print_nodes()

void depth() {
    int k;
    cin >> k;
    print_nodes(k, false);
} // end of depth()

void leaf() {
    print_nodes(0, true);
} // end of leaf()

int main() {
    string op;
    while (cin >> op) {
        switch (get_op_id(op)) {
            case 0: insert_string(); break;
            case 1: delete_string(); break;
            case 2: depth(); break;
            case 3: leaf(); break;
            default: delete root; return 0; // quit or unknown command
        }
    }
    delete root;
} // end of main()
