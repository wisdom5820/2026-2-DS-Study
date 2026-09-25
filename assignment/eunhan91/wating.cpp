/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: 29행 38행 49행
3. 어떤 도움이 필요했는지: 가장 주요하게 필요했던 부분은 디버깅이다. waiting 과제가 예외처리를 해야할 사항이 많았기 때문에
고려하지 못했던 상황에서 너무 자주 warning 혹은 error가 발생했고 이를 해결하기 위해 주로 도움을 받았다.
4. AI 제시 코드에서 추가, 개선한 부분:대부분 AI가 제시하는 코드는 토큰에 대한 고려가 들어가 있찌 않았다 대표적으로 38행의 insert문
내에서 이터레이터를 무한정 반복하였기에 c++20부터 추가된 ranges 헤더를 통해 깔끔하게 정리했다. 이외에도 29행의 함수를 검색을 통하여 
더 간단히 front를 비교하는 방식으로 교체하였따.
*/
#include <bits/stdc++.h>
#include <ranges>

using namespace std;

int main(){
    int N,k,p,idx;
    char pos;
    vector<vector<int>> room;
    cin>>N>>k;

    while(N--){
        cin>>pos>>p;

        if(room.empty()){
            if(pos=='+') room.push_back({p});
            continue;
        }

        auto it=ranges::upper_bound(room, p,{}, [](auto& x){return x.front();});

        if(it!=room.begin())
            --it;

        idx=it-room.begin();
        

        if(pos=='+') {
            room[idx].insert(ranges::upper_bound(room[idx], p),p);

            if(room[idx].size()==2*k){
                vector<int> v(room[idx].begin()+k, room[idx].end());
                room[idx].resize(k);
                room.insert(it+1,v);
            }   
        }

        
        else{
            if(ranges::find(room[idx],p)!=room[idx].end())
                room[idx].erase(ranges::find(room[idx],p));
            if(room[idx].empty())
                room.erase(it);
        }
        
    }

    for(auto &w:room)
        cout<<w.front()<<'\n';
}