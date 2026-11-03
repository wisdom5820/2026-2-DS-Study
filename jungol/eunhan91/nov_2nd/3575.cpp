#include <bits/stdc++.h>

using namespace std;

struct Node{
    int value_;
    Node * parent_=nullptr;
    Node * left_=nullptr;
    Node * right_=nullptr;
    
    public:
        Node* parent(){
            return parent_; //이편이 의미를 더 잘나타낸다고 생각했습니다.
        }


};

int main(){
    int p, ns, t;
    vector<Node> tree;

    cin>>p>>ns>>t;
    tree.reserve(p+1);

    for(int i=0; i<=p; ++i)
        tree.emplace_back(i);

    while(ns--){
        int parent, left, right;

        cin>>parent>>left>>right;

        tree[parent].left_=&tree[left ];
        tree[parent].right_=&tree[right];

        tree[left].parent_=&tree[parent];
        tree[right].parent_=&tree[parent];
    }

    stack<int> temp;
    int idx=t;

    while(true){
        temp.push(idx);
        
        if(tree[idx].parent()==nullptr) break; //root

        idx=tree[idx].parent()->value_;
    }

    cout<<temp.size()<<'\n';

    while(!temp.empty()){
        cout<<temp.top()<<'\n';
        temp.pop();
    }
}
