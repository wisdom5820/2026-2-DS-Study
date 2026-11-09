/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: 해당사항없음
3. 어떤 도움이 필요했는지: 디버깅에 주로 사용했습니다. 예외처리 하지 않은 부분이 있다던가, 로직에 에러가 발생한 부분이 있는지 확인하였습니다.
4. AI 제시 코드에서 추가, 개선한 부분:오류 확인용으로만 사용하였고 직접적으로 코드 수정에 이용하지는 않았습니다.
*/
#include <bits/stdc++.h>

using namespace std;

#define Max_size_iter(v) ranges::max_element((v),{},[](auto &x){return x.size();})
#define Min_size_iter(v) ranges::min_element((v),{},[](auto &x){return x.size();})

void get_yard_value(vector<stack<int>> &yard){
    int yard_size;

    cin>>yard_size;

    yard.resize(yard_size);

    for(int i=0; i<yard.size(); ++i){
        int size;

        cin>>size;

        while(size--){
            int weight;

            cin>>weight;

            yard[i].push(weight);
        }//end of inner_loop
    }//end of outer_loop
}//end of get_yard_value

bool need_sort(vector<stack<int>> & V){
    if(Max_size_iter(V)->size()-Min_size_iter(V)->size()<=1) return false;
    else                                                     return true;
}//end of need_sort

void move_container(vector<stack<int>> &V) {
    vector<int> candidate_yard_indices;
    int highest_yard_index, lowest_yard_index;

    int max_size = Max_size_iter(V)->size();

    for (int i = 0; i < V.size(); ++i)
        if (V[i].size() == max_size) candidate_yard_indices.push_back(i);

    highest_yard_index = *ranges::max_element(
        candidate_yard_indices, {}, [&V](int i) { return V[i].top(); }
    );
    // 이동할 컨테이너 결정

    lowest_yard_index = Min_size_iter(V) - V.begin();
    // 컨테이너의 위치 결정

    V[lowest_yard_index].push(V[highest_yard_index].top());
    V[highest_yard_index].pop();
} // end of move_container

void print_yards(const vector<stack<int>> &yards) {
    for (auto yard : yards) {
        if (yard.empty()) cout << 0;
        
        else {
            stack<int> temp_space;

            while (!yard.empty()) {
                temp_space.push(yard.top());
                yard.pop();
            }

            while (!temp_space.empty()) {
                cout << temp_space.top() << ' ';
                temp_space.pop();
            }
        }

        cout << '\n';
    }
}



int main(){
    vector<stack<int>> yard;

    get_yard_value(yard);

    /*input() && preprocessing()*/
    
    while(need_sort(yard))
        move_container(yard);
    
    /*computation()*/

    print_yards(yard);

    /*output()*/
}