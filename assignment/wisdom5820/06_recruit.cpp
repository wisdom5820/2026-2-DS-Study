/*
    1. 사용한 AI: ChatGPT
    2. 과제에서 활용한 부분: vector에서 erase() 사용 시 발생하는 인덱스 및 iterator 무효화 문제 해결,
                          POP 명령에서 선발 대상 탐색 로직 점검
    3. 어떤 도움이 필요했는지: 선발 과정 중 지원자를 바로 삭제하면 vector의 원소 위치가 변경되어 순서가
                            꼬이는 문제와, 각 대학의 지원자를 등수별로 순회하는 방법에 대해 도움을 받음
    4. AI를 통해 추가·개선한 부분: 선발된 지원자의 ID를 별도로 저장한 뒤 선발 과정이 끝난 후 삭제하도록
                                수정하고, 대학별 지원자 수를 이용해 다음 대학으로 이동하면서 rank별로
                                지원자를 탐색하는 방식을 참고하여 기존 코드를 수정함
*/

#include <bits/stdc++.h>
using namespace std;

struct recruit {
    string school;
    int id;
    int cote;
};

map<string, pair<int, int>> stat; // first : 지원자수, second : 코테 점수 합

bool comp(recruit& left, recruit& right) {

    if(stat[left.school].first != stat[right.school].first)  // 1. 지원자수
        return stat[left.school].first > stat[right.school].first;
    
    if(stat[left.school].second != stat[right.school].second)  // 2. 코테점수합
        return stat[left.school].second > stat[right.school].second;

    if(left.school == right.school) { // 같은 학교일 때 
        if (left.cote != right.cote)  // 3. 코테 성적순
            return left.cote > right.cote;

        return left.id > right.id; // 4. id
    }
    
    // 다른 학교인데 지원자수랑 코테점수합이 같을 때는,,,
    return left.school < right.school;
}

int main() {
    int N, k, total = 0; // total : 총 지원자
    cin >> N >> k; // k : 최저 지원자

    vector<recruit> samdori; // 지원자들 정보
    while(N--) {
        string str;
        int x, y;
        cin >> str >> x >> y; // school, id, cote

        if(str == "POP") {
            sort(samdori.begin(), samdori.end(), comp); 

            // test
            // for(auto [x, y, z] : samdori) 
            //     cout << x << ' ' << y << ' ' << z << '\n';

            
            int cnt = 0, rank = 0; // cnt : 선발 번호, rank : 학교 내에서 지원자 등수
            vector<int> selected; // 선발된 사람들 id 저장

            while(cnt < y) {
                bool found = false; // 선발 가능한가?

                for(int i = 0; i < total; ) {
                    string school = samdori[i].school; // 학교, 지원자 수
                    int schoolCnt = stat[school].first;

                    if(schoolCnt < k) { // 지원자가 k명 미만이면 패스
                        i += schoolCnt;
                        continue;
                    }

                    if(rank < schoolCnt) { // rank번째 지원자가 있을 때 
                        recruit R = samdori[i + rank]; 

                        cnt++; 
                        found = true; // 가능!!

                        if(cnt >= x && cnt <= y) { // 선발 구간 안에 들면 출력
                            cout << R.id << ' ';
                            selected.push_back(R.id);
                        }

                        if(cnt == y) break;
                    }

                    i += schoolCnt; // 다음 학교
                }

                if(!found) break; // 더이상 선발 불가능 -> while문 탈출

                rank++;
            }

            cout << '\n';
            
            // 선발이 모두 끝난 후 삭제
            for(int id : selected) {
                for(auto it = samdori.begin(); it != samdori.end(); it++) {
                    if(it->id == id) { 
                        // erase 하기 전에 정보 수정
                        stat[it->school].first--; 
                        stat[it->school].second -= it->cote;
                        total--;

                        samdori.erase(it);

                        break;
                    }
                }
            }
        } else {
            samdori.push_back({str, x, y});
            stat[str].first++; // 지원자수 +1
            stat[str].second += y; // 코테 점수 더하기

            total++; // 총 지원자 수 +1
        }
    }

    return 0;
}