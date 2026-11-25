/*
    1. 사용한 AI: ChatGPT
    2. 과제에서 활용한 부분: 이진 탐색 트리(BST)의 삽입, 삭제, 깊이별 노드 탐색 및 리프 노드 탐색 구현
    3. 어떤 도움이 필요했는지: 
        처음에는 list<node>와 vector<vector<string>>을 사용해 트리와 깊이별 노드를 관리하려 했으나, 
        노드 삭제 시 트리 구조와 깊이 정보가 변경되는 문제를 해결하기 위해 도움을 요청함.
    4. AI를 통해 추가·개선한 부분: 
        별도의 깊이별 벡터 대신 루트 포인터를 이용하는 구조로 변경함. 
        또한 재귀 함수를 활용한 삽입 및 탐색 기능을 구현.
*/

// 95점

#include <bits/stdc++.h>
using namespace std;

struct node {
    string name;
    node* left; // 왼쪽 자식 노드 주소
    node* right; // 오른쪽 자식 노드 주소
};

/* == 노드 삽입 == */
// root가 항상 전체 트리의 루트를 의미하지는 않음
// 재귀 호출 할 때마다 현재 탐색 중인 서브트리의 루트 전달
// 재귀 함수가 내려가면서 삽입 위치 찾고, 돌아오면서 노드 간의 연결 설정
node* insert(node* root, string str) {
    if (root == nullptr) 
        return new node{str, nullptr, nullptr}; // 비어있는 위치에 도달한 경우 새로운 노드 생성

    if (str < root->name) { // 삽입할 문자열이 현재 노드보다 작은 경우
        root->left = insert(root->left, str);
    }
    else if (str > root->name) { // 삽입할 문자열이 현재 노드보다 큰 경우
        root->right = insert(root->right, str);
    }

    return root; // 현재 노드의 주소 반환
}

/* == 노드 삭제 == */
node* removeNode(node* root, string str) {
    if (root == nullptr) return nullptr; // 삭제할 노드가 존재하지 않는 경우 -> nullptr 반환

    if (str < root->name) {
        root->left = removeNode(root->left, str);
    } 
    else if (str > root->name) {
        root->right = removeNode(root->right, str);
    } 
    else { // str == root->name 삭제할 노드 찾았을 때

        // 왼쪽 자식이 없는 경우
        if (root->left == nullptr) {
            node* temp = root->right; // 현재 노드 삭제하기 전에 자식 주소 보관
            delete root;
            return temp;
        }

        // 오른쪽 자식이 없는 경우
        if (root->right == nullptr) {
            node* temp = root->left; // 현재 노드 삭제하기 전에 자식 주소 보관
            delete root;
            return temp;
        }

        // temp에 nullptr이 저장될 수도 있음 <= 리프 노드를 삭제하는 경우

        // 자식이 둘 다 있는 경우
        // 왼쪽 서브트리에서 가장 큰 값 찾기
        node* temp = root->left;
        while (temp->right != nullptr)
            temp = temp->right; // 왼쪽 서브트리에서 오른쪽 자식이 없을 때까지 이동 -> 최댓값 찾을 수 있음

        root->name = temp->name; // 삭제할 노드의 문자열을 왼쪽 서브트리의 최댓값으로 덮어씀
        root->left = removeNode(root->left, temp->name); // 기존 노드는 재귀적으로 삭제
    }

    return root;
}

/* 특정 깊이의 노드 찾기 */
void getDepth(node* root, int current, int target, vector<string>& result) {
    if (root == nullptr) return;

    if (current == target) {
        result.push_back(root->name);
        return;
    }

    getDepth(root->left, current + 1, target, result);
    getDepth(root->right, current + 1, target, result);
}

/* 리프 노드 찾기 */
void getLeaf(node* root, vector<string>& result) {
    if (root == nullptr) return; // 현재 노드가 존재하지 않으면 탐색 종료

    if (root->left == nullptr && root->right == nullptr) { // 왼쪽 자식과 오른쪽 자식 모두 없다 == 리프 노드
        result.push_back(root->name);
        return;
    }

    // 리프 노드가 아니면
    // 왼쪽, 오른쪽 자식 재귀적으로 탐색
    getLeaf(root->left, result);
    getLeaf(root->right, result);
}

/* 결과 출력 */
void printResult(vector<string>& result) {
    // sort(result.begin(), result.end()); // 먼저 사전순으로 정렬. 생략 가능

    if (result.empty()) {
        cout << "NO";
    }
    else {
        // for (string s : result)
        //    cout << s << ' ';

        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
    }

    cout << '\n';
}

/* 메모리 해제 */
// insert()에서 new를 이용해 노드를 동적으로 생성했기 때문에
// 프로그램이 끝나기 전에 메모리를 해제해줘야 함
void clearTree(node* root) {
    if (root == nullptr) return; // 현재 노드가 없으면 해제할 메모리도 없으므로 종료

    // 재귀적으로 삭제
    clearTree(root->left); 
    clearTree(root->right);
    // 왼쪽과 오른쪽 자식이 삭제된 후 현재 노드 삭제 (Postorder Traversal)
    delete root;
}

int main() {
    /* 자료구조 */
    node* root = nullptr;

    /* 작업 시작 */
    string cmd;
    while (cin >> cmd) {
        if (cmd == "quit") break;

        else if (cmd == "+") {
            string str;
            cin >> str;

            root = insert(root, str);
        }
        else if (cmd == "-") {
            string str;
            cin >> str;

            root = removeNode(root, str);
        }
        else if (cmd == "depth") {
            int n;
            cin >> n;

            vector<string> result;
            getDepth(root, 1, n, result);

            printResult(result);
        }
        else if (cmd == "leaf") {
            vector<string> result;
            getLeaf(root, result);

            printResult(result);
        }
    }

    clearTree(root);
}