#include <bits/stdc++.h>
using namespace std;
using P = pair<string, vector<int>>;  
// [AI] 반복되는 자료형을 using으로 별칭을 지정해 코드를 간결하게 작성함

vector<int> priority;

// [AI] 6개 조건문 대신 for문으로 순차 비교하도록 작성함
bool comp(const P& a, const P& b) {
    for(int p : priority) {
        int A = a.second[p-1], B = b.second[p-1];
        if(A != B) 
            return (p == 6) ? A < B : A > B; // 큰 값 우선 (m6은 예외)
    }
    return a.first < b.first; // 모든 지표가 같을 때는 문자열 사전식 순서로
}

int main() {
    int N, i, x; // N : 학생수, i : 반복문 인덱스, x : 입력공간
    cin >> N;

    for(i = 0; i < 6; i++)
        cin >> x, priority.push_back(x);  // 우선순위 배열

    //vector<vector<int>> grade(N); // 성적
    // [AI] grade 배열에 점수를 저장하지 않고 입력과 동시에 통계값을 계산하도록 수정함
    vector<P> students(N);  // 통계

    for (i = 0; i < N; i++) {
        cin >> students[i].first;

        auto& s = students[i].second;
        s.resize(6);
        s[2] = 100;

        while(cin >> x, x != -1) {
            s[0]++; // 1. 출석 횟수
            s[1] += x; // 2. 점수 총합 
            s[2] = min(s[2], x);  // 3. 최저 점수
            s[3] = max(s[3], x);  // 4. 최고 점수
            if(x == 100) s[4]++;  // 5. 100점 만점 횟수
            if(x <= 50) s[5]++;  // 6. 50점 이하 횟수
        }
    }

    sort(students.begin(), students.end(), comp);

    for(auto x : students) cout << x.first << '\n';
}