#include<bits/stdc++.h>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> inp;
    //vector<int> oup;
    int i=0;
    for (; i< N; i++){
        int no;
        cin >> no;
        inp.push_back(no);
    }
    int check = inp[N-1];
    int cnt = 1;
    for (i = N-2; i>= 0; i--){
        if (check < inp[i]){
            cnt++;
            check = inp[i];
        }
    }
    cout << cnt;
}
