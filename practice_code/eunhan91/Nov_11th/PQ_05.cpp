#include <bits/stdc++.h>

using namespace std;

struct example{
    bool is_reverse;

    public:
        example(const bool & revparam=false){
            is_reverse=revparam;
        }

        bool operator() (const int & lhs, const int & rhs){
            if(is_reverse) return lhs>rhs; //min heap
            else           return lhs<rhs; //max heap
        }
};

int main(){
    vector<int> myvec{1,2,3,4,5,6,7,8,9,10};

    priority_queue<int, vector<int>, example> max_heap(myvec.begin(), myvec.end());
    priority_queue<int, vector<int>, example> min_heap(myvec.begin(), myvec.end(), example(true));

    cout<<"\n>Print Max heap\n";

    while(!max_heap.empty()){
        cout<<max_heap.top()<<" ";

        max_heap.pop();
    }

    cout<<"\n>Print Mix heap\n";

    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";

        min_heap.pop();
    }

    /*
    reference:Application 400 — PQ compare.cpp
    */
}