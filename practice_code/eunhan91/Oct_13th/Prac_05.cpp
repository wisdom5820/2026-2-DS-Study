#include <bits/stdc++.h>

using namespace std;



#define N_loop 100000000
#define Br cout<<'\n';

void test1(){
    chrono::system_clock::time_point mybegin, myend;
    chrono::duration<double, milli> sec;
    double t_sec;

    int a;

    mybegin=chrono::system_clock::now();
    for(int64_t i=0; i<N_loop; ++i)
        a=(i<<3)+i;
    myend=chrono::system_clock::now();
    sec=myend-mybegin;
    t_sec=sec.count();

    cout<<t_sec;
    Br

    mybegin=chrono::system_clock::now();
    for(int64_t i=0; i<N_loop; ++i)
        a=9*i;
    myend=chrono::system_clock::now();
    sec=myend-mybegin;
    t_sec=sec.count();

    cout<<t_sec;
    Br

    mybegin=chrono::system_clock::now();
    for(int64_t i=0; i<N_loop; ++i)
        a=i+i+i+i+i+i+i+i+i;
    myend=chrono::system_clock::now();
    sec=myend-mybegin;
    t_sec=sec.count();

    cout<<t_sec;
    Br
}

void test2(){
    chrono::system_clock::time_point mybegin, myend;
    chrono::duration<double, milli> sec;
    double t_sec;

    int a;

    mybegin=chrono::system_clock::now();
    for(int64_t i=0; i<N_loop; ++i)
        a=i<<3;
    myend=chrono::system_clock::now();
    sec=myend-mybegin;
    t_sec=sec.count();

    cout<<t_sec;
    Br

    mybegin=chrono::system_clock::now();
    for(int64_t i=0; i<N_loop; ++i)
        a=8*i;
    myend=chrono::system_clock::now();
    sec=myend-mybegin;
    t_sec=sec.count();

    cout<<t_sec;
    Br

    mybegin=chrono::system_clock::now();
    for(int64_t i=0; i<N_loop; ++i)
        a=i+i+i+i+i+i+i+i;
    myend=chrono::system_clock::now();
    sec=myend-mybegin;
    t_sec=sec.count();

    cout<<t_sec;
    Br
}

int main(){
    test1();
    Br
    test2();

    /*
    286.509
    306.855
    804.415

    789.9
    306.279
    808.535
    */
}