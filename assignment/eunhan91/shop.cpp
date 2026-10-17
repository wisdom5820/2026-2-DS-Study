/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: release_coustomer function
3. 어떤 도움이 필요했는지: assign과 clear는 큰 어려움이 없었지만, 나가는 고객에 대한 함수를 작성하는 부분에서 어려움을 겪어 token초과가 발생했다. views::reverse를 적절히 사용하여 해결하는 방식을 채택 왜에도 자잘한 로직 에러들을 해결하는 데 도움을 받았다.
4. AI 제시 코드에서 추가, 개선한 부분:해당사항 없음, 다만 해결 방법에 관한 조언을 구하고 직접 코드를 작성하려 했습니다.
*/
#include <bits/stdc++.h>
#include <ranges>

using namespace std;

vector<pair<int, int>> COUNTER_DECISION;
queue<int> CUSTOMER_LIST_UP;

#define Out_all_list(x) do{while(!(x).empty()){cout<<(x).front()<<'\n';(x).pop();}}while(0)
#define T_min(x) ranges::min_element((x),{},[](auto v){return v.second;})

void assign_customer(){
    auto it = ranges::find(COUNTER_DECISION, pair<int, int>{0, 0});
    cin >> it->first >> it->second;
}

void release_customer(){
    int t = INT_MAX;

    for(auto [id, time] : COUNTER_DECISION)
        if(time > 0) t = min(t, time);

    for(auto& counter : COUNTER_DECISION | views::reverse){
        if(counter.second == 0) continue;

        counter.second -= t;

        if(counter.second == 0){
            CUSTOMER_LIST_UP.push(counter.first);
            counter = {0, 0};
        }
    }
}

void clear_buffer(){
    while(ranges::any_of(COUNTER_DECISION, [](auto x){return x != pair<int, int>{0, 0};})) release_customer();
}

int main(){
    int n_customer, n_counter;

    cin>>n_customer>>n_counter;

    COUNTER_DECISION.resize(n_counter);

    while(n_customer--){
        if(ranges::all_of(COUNTER_DECISION,[](auto x){return x!=pair<int, int>{0,0};})) release_customer();

        if(ranges::any_of(COUNTER_DECISION,[](auto x){return x==pair<int, int>{0,0};})) assign_customer();

        if(n_customer==0) clear_buffer();
    }

    Out_all_list(CUSTOMER_LIST_UP);
}