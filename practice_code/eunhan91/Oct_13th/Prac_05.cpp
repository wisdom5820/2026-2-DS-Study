#include <bits/stdc++.h>

using namespace std;

#define N_array 100000000
#define M 10000 
#define compute_time do{sec=myend-mybegin; t_sec=sec.count(); cout<<t_sec<<'\n';}while(0);

int main(){ 
    double t_sec;
    chrono::duration<double, milli> sec;
    chrono::system_clock::time_point mybegin, myend;

    vector<int> v(N_array);

    mybegin=chrono::system_clock::now();
    for(int i=0; i<M; ++i)
        for(int j=0; j<M; ++j) v[M*i+j]=i+j;
    myend=chrono::system_clock::now();

    compute_time

    mybegin=chrono::system_clock::now();
    for(int j=0; j<M; ++j)
        for(int i=0; i<M; ++i) v[M*i+j]=i+j;
    myend=chrono::system_clock::now();

    compute_time

    mybegin=chrono::system_clock::now();
    for(int i=0; i<N_array; ++i) v[i]=i;
    myend=chrono::system_clock::now();

    compute_time

    /*
    인덱스 접근은 모두 O(1)이지만, 캐시 활용에 따라 실제 접근 시간은 달라진다
    reference:Arithmetic 350 - row col majojr 2D array scan.cpp
    */
}