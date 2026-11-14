#include <bits/stdc++.h>

using namespace std;

struct Data
{
    int d;
};

bool operator< (const Data & d1, const Data & d2){
    return d1.d > d2.d;
}


int main(){
    vector<int> myvector{1,2,3,4,5,6,7,8,9,10};

    priority_queue<Data> myPQ(myvector.begin(), myvector.end());

    while(!myPQ.empty()){
        cout<<myPQ.top().d<<" ";

        myPQ.pop();
    }
}