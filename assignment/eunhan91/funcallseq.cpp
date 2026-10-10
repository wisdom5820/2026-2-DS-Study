/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: find_statement 함수의 전체적인 작성
3. 어떤 도움이 필요했는지: 위치를 탐색하는 과정 자체가 어렵게 느껴졌고 예외처리 후 람다 함수를 이용한 재귀함수로서 문제를 해결하는 방법 자체가 생각나지 않아 도움을 받게 되었습니다.
4. AI 제시 코드에서 추가, 개선한 부분:예외처리 부분은 모호함이 강한 코드가 작성돼어 직접 수정하였고, function을 이용하여 람다함수의 반환형을 결정하게 수정하였습니다.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long Dlong;

map<char, vector<string>> FUNCTIONS;
map<char, int> STATE; //value가 0일경우 첫 방문하는 함수, 1일 경우 처리 중인 함수 2일 경우 처리 완ㄹ교한 함수
map<char, Dlong> SIZES;

void fill_FUNCTIONS(){
    char function_name;
    string statement;

    cin>>function_name;

    while(cin>>statement && statement != "$")
        FUNCTIONS[function_name].push_back(statement);
}

bool analyze_function(char function_name){
    if(STATE[function_name]==1) return false; //infinite_loop 
    if(STATE[function_name]==2) return true; 

    STATE[function_name]=1;
    SIZES[function_name]=0;

    for(auto w:FUNCTIONS[function_name]){
        if(isupper(w.front())){
            if(analyze_function(w.front())) SIZES[function_name]+=SIZES[w.front()];

            else return false;
        }

        else SIZES[function_name]+=1;
    }

    STATE[function_name]=2;
    return true;
}

string find_statement(Dlong bound){
    if(abs(bound)>SIZES['M']) return "NONE";

    if(bound < 0) bound = SIZES['M'] + bound + 1;

    function<string(char, Dlong)> find_in =[&](char name, Dlong position) -> string {
        for(const auto& w : FUNCTIONS[name]){
            if(isupper(w.front())){
                char next = w.front();
                if(position <= SIZES[next]) return find_in(next, position);

                position -= SIZES[next];
            }
            else{
                if(position == 1) return string(1, name) + "-" + w;

                --position;
            }
        }

        return "NONE";
    };

    return find_in('M', bound);
}

int main(){
    int n_func;
    vector<Dlong> bound(2);

    cin>>n_func>>bound[0]>>bound[1];

    while(n_func--)
        fill_FUNCTIONS();
    //input()

    if(!analyze_function('M')){
        cout<<"DEADLOCK";
        return 0;
    }
    //prepro()

    string result1=find_statement(bound[0]);
    string result2=find_statement(bound[1]);
    //compute()

    cout<<result1<<'\n'<<result2;
    //output()
}
