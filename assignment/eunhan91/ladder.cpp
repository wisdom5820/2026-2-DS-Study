/*
1. 사용한 AI: 5.6 Terra(High)
2. 과제에 활용한 부분: 기본 로직짜기, 컨테이너 구성
3. 어떤 도움이 필요했는지: 개인적으로 person이라는 객체에 집중하여 각 인스턴스마다 고유의 현재 depth, 위치 등의 쓸모없는 인스턴스 변수를 부여했고
결과적으로 구현된 소스코드는 토큰 제한을 100 token이상 초과하는 부적절한 코드가 만들어졌다. 때문에 기초적인 로직 구성부터 실수가 있음을 깨닫고, AI에게
질문함으로서 horizon_depth에 해당하는 변수를 오름차순으로 탐색하여 양쪽을 스왑하는 방식으로 depth에 집중하는 구조로 변경하였다. 이외에도 코드 작성 전
적절한 DS를 공부하고 구현하기 위해 어떤 container를 사용할지 추천받아 사용하였다.
4. AI 제시 코드에서 추가, 개선한 부분:변수의 선언방식을 변경하고 반복문의 구조를 다듬어 토큰 사용을 줄였다. 입력 시 쓸모없는 값이 -1 역시 vector에 
저장하는 코드를 수정하였다. 
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int i, N, depth, min, min_index;
    cin>>N;
    vector<int> person(N);
    vector<vector<int>> horizon_depth(N-1);
    vector<int> index(N-1);
    
    for(i=0; i<N-1; i++)
        while(cin>>depth && depth>=0)
            horizon_depth[i].push_back(depth);

    for(i=0; i<N; i++)
        person[i]=i;

    while(1){
        min=1001;

        for(i=0; i<N-1; i++)
            if(index[i]<horizon_depth[i].size() && horizon_depth[i][index[i]]<min)
                min_index=i, min=horizon_depth[i][index[i]];//남은 것 중 가장 작은값 탐색 후 인덱스 저장
        

        if(min==1001) break;

        swap(person[min_index], person[min_index+1]);
        index[min_index]++;
    
    }   
        
    for(i=0; i<N; i++)
        cout<<char(person[i]+97)<<" ";
}
