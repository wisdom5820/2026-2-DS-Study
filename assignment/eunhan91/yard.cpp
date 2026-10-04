/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: 해당사항없음
3. 어떤 도움이 필요했는지: 디버깅에 주로 사용했습니다. 예외처리 하지 않은 부분이 있다던가, 로직에 에러가 발생한 부분이 있는지 확인하였습니다.
4. AI 제시 코드에서 추가, 개선한 부분:오류 확인용으로만 사용하였고 직접적으로 코드 수정에 이용하지는 않았습니다.
*/
#include <bits/stdc++.h>
#include <ranges>

using namespace std;

#define size_MAX(v) ranges::max_element((v),{},[](auto &x){return x.size();})
#define size_MIN(v) ranges::min_element((v),{},[](auto &x){return x.size();})

bool need_sort(vector<stack<int>> & V){
    if(size_MAX(V)->size()-size_MIN(V)->size()<=1) return false;
    else                                           return true;
}//end of need_sort

void moving_yard(vector<stack<int>> & V){
    vector<int> container_to_move;
    int highest_one, lowest_one;

    int max_size=size_MAX(V)->size();

    for(int i=0; i<V.size(); ++i)
        if(V[i].size() == max_size)
            container_to_move.push_back(i);

    highest_one=*ranges::max_element(container_to_move,{},[&V](int i){return V[i].top();});
    //이동할 컨테이너 결정

    lowest_one=size_MIN(V)-V.begin();
    //컨테이너의 위치 결정

    V[lowest_one].push(V[highest_one].top());
    V[highest_one].pop();
}//end of moving_yard

void print_stack_from_bottom(stack<int> &S){
    stack<int> temp_space;

    while(!S.empty()){
        temp_space.push(S.top());
        S.pop();
    }

    while(!temp_space.empty()){
        cout<<temp_space.top()<<' ';
        temp_space.pop();
    }
}

int main(){
    vector<stack<int>> yard;
    int yard_size;

    cin>>yard_size;

    yard.resize(yard_size);

    for(int i=0; i<yard.size(); ++i){
        int size, weight;

        cin>>size;

        while(size--){
            cin>>weight;

            yard[i].push(weight);
        }//end of inner_loop
    }//end of outer_loop

    /*input() && preprocessing()*/
    
    while(need_sort(yard))
        moving_yard(yard);
    
    /*computation()*/

    for(auto w:yard){
        if(w.empty()) cout<<0;
        else          print_stack_from_bottom(w);

        cout<<'\n';
    }

    /*output()*/
}