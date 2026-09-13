/*
1. 사용한 AI: 5.6 Sol(High)
2. 과제에 활용한 부분: 46행~54행
3. 어떤 도움이 필요했는지: 로직 작성한 뒤 실행했으나 의도한 결과가 나오지 않아 AI를 활용해 디버깅하였다.
while문의 조건에 end<event.size()가 빠져 범위초과 상태에 빠지고 있고 end의 기준을 모호하게 잡아 잘못된 값을 swap을
하고 있음을 깨달았다. 
4. AI 제시 코드에서 추가, 개선한 부분:AI는 첫부분을 start와 같은 identifier를 사용하여 저장할 것을 요구하였으나 
적절히 i를 사용하여 end=i와 i만을 사용하여 computation부분을 구성하였다. end만을 사용하니 
event[end].first==event[end+1].first && event[end].second+1 == event[end+1].second) 같은 부분에서
end를 연속 구간의 마지막 원소로서 사용하여 더욱 모호함없이 코드를 구성할 수 있었다.

cf: for (i = 0; i < event.size(); ) {        
    start = i;
    end = i + 1;

    while (end < event.size() && event[start].first == event[end].first && event[end-1].second + 1 == event[end].second)
        end++;        
    
    swap(status[event[start].second], status[event[end-1].second + 1]);
    i = end;
} AI가 제시했던 코드
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int i, depth, N, end;
    cin>>N;

    vector<pair<int, int>> event; //가로막대의 정보 depth, box
    vector<int> status;//현재 축의 문자 

    for(i=0; i<N-1; i++)
        while(cin>>depth, depth>0)
            event.push_back({depth, i});
            
            
    for(i=0; i<N; i++)
        status.push_back(i);//input();
    
    sort(event.begin(), event.end());//prepro();


    for(i=0; i<event.size();){        
        end=i;

        while(end+1<event.size() && event[end].first==event[end+1].first && event[end].second+1 == event[end+1].second)
            end++;             

        swap(status[event[i].second], status[event[end].second+1]);
        i=end+1;
    }//computation();

    for(auto c: status)
        cout<<char(c+'A')<<" ";//output();
}