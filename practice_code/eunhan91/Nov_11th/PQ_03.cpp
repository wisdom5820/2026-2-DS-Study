#include <bits/stdc++.h>

using namespace std;

int STANDARD=10;

bool compare (const int & lhs, const int & rhs){//parent, child
    if(STANDARD%2==0) return lhs>rhs;//min heap

    else              return lhs<rhs;//max heap;     
}

int main(){
    vector<int> myvec{1,2,3,4,5,6,7,8,9,10};

    ranges::make_heap(myvec, compare);

    while(!myvec.empty()){
        ranges::pop_heap(myvec,compare);

        cout<<myvec.back()<<" ";

        myvec.pop_back();
        
        STANDARD--;
    }

    cout<<'\n';
    STANDARD=10;
    /*
    UB 입니다!

    while(!myPQ.empty()){
        cout<<myPQ.top()<<" ";

        myPQ.pop();
    }
    */

    myvec={1,2,3,4,5,6,7,8,9,10};

    ranges::make_heap(myvec, compare);

    
    while(!myvec.empty()){
        ranges::pop_heap(myvec,compare);

        cout<<myvec.back()<<" ";

        myvec.pop_back();

        STANDARD--;

        ranges::make_heap(myvec, compare);        
    }

    cout<<'\n';

    /*
    reference:STL-PQ- 170 - 나이 alternating.cpp
    */
}