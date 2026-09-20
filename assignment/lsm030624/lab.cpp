/*

1. 사용한 AI (model 까지) :
    Gemini 3.6 Flash, GPT-5.6 Luna

2. 과제에서 활용한 부분 :
    sort에 사용자 정의 비교 함수의 적용 및 토큰 수 줄이기 목적

3. 어떤 도움이 필요했는지 :
    문제에서 의도한 vector의 sort를 활용하되 사용자 정의 비교 함수, 그 중에서도 람다 함수를 이용하여 정렬을 하고자 했습니다. 다음으로는 토큰 수를 줄이기 위해 사용하였습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    인덱스 접근을 목적으로 for (int i = 0; i < 6; i++){...}를 사용하기 보다 for(auto& p:str_list){...}나, for(auto& p:str_list){...}를 통해서도 인덱스 접근이 가능하고, 토큰 수를 줄일 수 있었습니다.
    또한 und += it <= 50;룰 통해서는 간단히 조건에 따라 비교하여 개수를 증가시키는 경우에는 꼭 if를 사용하지 않아도 됨을 알 수 있었습니다.
    그리고 vector에 한번에 연속적으로 넣는 경우에는 일일이 push_back()을 하는 것보다는 전체를 묶어서 대입 연산을 하는 것이 토큰 수를 줄일 수 있었습니다.

*/

#include<bits/stdc++.h>

using namespace std;

vector<int> cm;

auto cmp = [](const auto& a, const auto& b){
    for(int i:cm)
        if(a.second[i]!=b.second[i])
            return i==6?a.second[i]<b.second[i]:a.second[i]>b.second[i];
    return a.first<b.first;
};

int main () {
    int N;
    cin >> N;
    cin.ignore();
    string pr;
    getline(cin, pr);
    stringstream ss(pr);
    int it;
    while (ss >> it)
        cm.push_back(it);
    vector<pair<string, vector<int>>> str_list(N);
    for(auto& p:str_list){
        vector<int> temp;
        int und = 0;
        getline(cin, pr);
        stringstream ss(pr);
        ss >> p.first;
        int it;
        while(ss>>it&&it!=-1){
            temp.push_back(it);
            und += it <= 50;
        }
        p.second = {-1,
                    temp.size(),
                    accumulate(temp.begin(), temp.end(), 0),
                    *min_element(temp.begin(),temp.end()),
                    *max_element(temp.begin(), temp.end()),
                    count(temp.begin(), temp.end(), 100),
                    und};
    }
    sort(str_list.begin(), str_list.end(), cmp);

    for(auto& p:str_list)
        cout<<p.first<<endl;
}
