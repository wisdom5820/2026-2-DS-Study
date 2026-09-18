/*
1. 사용한 AI: GPT-6 Astra (High)
2. 과제에 활용한 부분: 28행, 44행
3. 어떤 도움이 필요했는지: 소스코드 작성 이후 UB 혹은 좋지 않은 코딩 습관이 있는지 확인하기 위하여 디버깅 용으로 사용했다.
4. AI 제시 코드에서 추가, 개선한 부분:해당 사항 없음. 다만 result 변수 선언과 v.size를 사용하는 로직은 직접 구성하였고,
해당 부분에서 size가 unsigned int인 것을 고려하지 못한 점과 컴파일러의 초기화 경고를 유발할 수 있다는 문제점을 확인한
후 코드를 일부분 수정하였다.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,j,i,n,result=0;
    string str;

    cin>>n;

    vector<pair<array<int, 6>, string>> students(n);
    array<int, 6> priority{};//우선순위 값들

    for(auto &value:priority){
        cin>>value;
        --value;
    }

    for(i=0; i<n; ++i){
        vector<int> v;

        cin>>str;

        while(cin>>x&& x>0)
            v.push_back(x);

        students[i].second=str;

        if(v.empty()) continue;

        auto It_begin=v.begin(), It_end=v.end();
        
        for(j=0; j<6; ++j){//우선순위 값들을 꺼낸다

            switch (priority[j])
            {
            case 0:
                result=-static_cast<int>(v.size());
                break;
            case 1:
                result=-accumulate(It_begin, It_end, 0);
                break;
            case 2:
                result=-*min_element(It_begin, It_end);
                break;
            case 3:
                result=-*max_element(It_begin, It_end);
                break;
            case 4:
                result=-count(It_begin, It_end, 100);
                break;
            case 5:
                result=count_if(It_begin, It_end, [](int x){return x<=50;});
                break;
            }

            students[i].first[j]=result;
        }   
}

    sort(students.begin(), students.end());

    for(i=0; i<n; ++i)
        cout<<students[i].second<<'\n';
}