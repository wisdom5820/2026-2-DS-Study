/*
1. 사용한 AI: GPT-6 Astra(High)
2. 과제에 활용한 부분: 36행 48행 57행
3. 어떤 도움이 필요했는지: 초기 사용 컨테이너 결정과 디버깅을 하는데 주로 도움을 받았다. 대표적으로 대학별 학생 순위를 정렬하던중 sort함수를 잘못 사용하던 것을
36 라인과 같이 점수와 아이디 내림차순으로 정리하였고 이외에도 예외처리가 부족하여 테스트 케이스를 통과하지 못하던 48행과 57행등에서 큰 도움을 받았다.
4. AI 제시 코드에서 추가, 개선한 부분:예외 처리 실수와 관련하여 도움을 받았기에 AI 코드를 거의 그대로 사용하였으나 36 행에 한하여 ranges base로 간단하게 코드
로서 구현하였다.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, k, id, score, lower_bound, upper_bound,i ;
    string op ;

    map<string, vector<pair<int, int>>> db; //점수 id

    vector<tuple<int, int, string>> order;//인원 점수합 대학이름

    cin>>N>>k ;

    while(N--){
        cin>>op;

        if(op=="POP"){
            vector<int> rank;

            cin>>lower_bound>>upper_bound;

            order.clear();

            for(auto &[name, data]:db){
                if(data.size() < k) continue;

                ranges::sort(data, greater<>()); // ** 도움밭은 라인

                int sum=0;

                for(auto [score, _]:data)
                    sum+=score;

                order.push_back({data.size(), sum, name});
            }

            ranges::sort(order,greater<>());

            int maxCnt = order.empty() ? 0 : get<0>(order[0]); // 도움받은 라인


            for(i = 0; i < maxCnt; ++i)
                for(auto& [cnt, sum, name] : order)
                    if(i < cnt)
                        rank.push_back(db[name][i].second);

            for(i = lower_bound - 1;
                i < upper_bound && i < (int)rank.size(); ++i){ // 도움받은 라인 
                cout << rank[i] << ' ';

                for(auto& [name, data] : db)
                    erase_if(data, [&](const auto& a){
                        return a.second == rank[i];
                    });
            }
            
            cout<<'\n';


        }

        else{
            cin>>id>>score;

            db[op].push_back({score, id});
        }
    }
}