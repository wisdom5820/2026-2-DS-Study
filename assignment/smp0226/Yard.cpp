#include<bits/stdc++.h>
#include<climits>
using namespace std;



void printYard(stack<int> s) {
    if (s.empty()) {
        cout << 0;
        return;
    }
    
    vector<int> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }
    
    
    for (int i = (int)temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
}
   

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,id;
    if (!(cin >> N)) return 0;
    vector<stack<int>> yards(N);
    for(int i=0;i<N;i++){
        int s;
        cin>>s;       
        for(int j=0;j<s;j++){
            cin>>id;
            yards[i].push(id);
        }
              
    }
    
while(true){
    int yd_max=-1, yd_idx=-1;
    int yd_min=INT_MAX, yd_minidx=-1;

    for(int i=0;i<N;i++){
        int current_size=yards[i].size();
        
        if(current_size>yd_max){ yd_max=current_size, yd_idx=i;
        }
        else if (current_size==yd_max && current_size > 0) {
            if (yards[i].top() > yards[yd_idx].top()) {
                    yd_idx = i;
                }
        }
        
        
        if(current_size<yd_min) {yd_min=current_size, yd_minidx=i;
        }


        

    }

    if (yd_max - yd_min <= 1) break;
    
    int moving_container=yards[yd_idx].top();
    yards[yd_idx].pop();
     yards[yd_minidx].push(moving_container);

        
}


for (int i = 0; i < N; i++) {
        if (yards[i].empty()) {
            cout << 0;
        } else {
            printYard(yards[i]);
        }
        cout << "\n";
    }

    return 0;
}









//claude 5 sonnet
//stl의 stack을 사용하라고 하셔서 stack을 어떻게 사용하는것인지 공부하였다 pop과 push 그리고 top을 통해 가장 겉에 있는 값 들을 알 수 있었다

//마지막에 출력할때 stack은 값들을 인덱스로 접근할수가 없음으로  어떻게 출력할지를 고민하다가 재귀함수를 통해 쉽게 출력할 수 있다는것을 알수잇었다 또한 원본 스텍도 보존할수 있었다

//printBottomup이라는 재귀함수를 이용했다 재귀함수가 s를 값으로 받기 때문에 복사본이 만들어진다 재귀를 타고 들어가면서 pop을 계속하다가 스텍이 비면 다시 거꾸로 돌아오면서 출력하기 때문에 맨 밑에 있던값을 가장 먼저 출력할 수 있다
//이렇게 재귀를 이용하려 했지만 함수가 호출될때마다 스택전체가 복사되어서 time limit exceeded을 일으켰다 따라서 재귀대신 vector를 이용여여 처리했다 
// ios_base::sync_with_stdio(false) cin.tie(NULL);----->입출력의 속도를 비약적으로 향상시켰다