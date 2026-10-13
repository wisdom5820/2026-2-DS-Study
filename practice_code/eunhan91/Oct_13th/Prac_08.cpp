#include <bits/stdc++.h>

using namespace std;

#define N_rep 10000000
#define compute_time do{sec=myend-mybegin; t_sec=sec.count(); cout<<t_sec<<'\n';}while(0)

void fill_arr(int & a){
    a=0;
}

int main(){
    chrono::system_clock::time_point mybegin, myend;
    chrono::duration<double, milli> sec;
    double t_sec;

    vector<int> v;
    v.resize(N_rep);

    mybegin=chrono::system_clock::now();
    for(auto &i:v)
        i=0;
    myend=chrono::system_clock::now();

    compute_time;

    mybegin=chrono::system_clock::now();
    for_each(v.begin(), v.end(), fill_arr);
    myend=chrono::system_clock::now();

    compute_time;

    /*
    real-time Linux 기반 결과값
    stdout
    32.859
    40.2393
    그렇게 빠른 방식은 아닌듯.

    reference:Generic_algo - for_each with class.cpp
    */
}