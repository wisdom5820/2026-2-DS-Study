/*
- 사용한 AI: ChatGPT

- 과제에서 활용한 부분: list의 iterator를 이용한 파일 관리

- 어떤 도움이 필요했는지:
    compact 구현 중 erase() 이후 iterator 처리 방법과 startPos 갱신 방법을 확인하고자 했다.

- AI를 통해 추가, 개선한 부분:
    erase()가 다음 노드의 iterator를 반환한다는 점을 이해하고, 
    compact 과정에서 빈 공간을 삭제한 뒤 pos 변수를 이용해 각 파일의 startPos를 재계산하도록 수정하였다.
*/

#include <bits/stdc++.h>
using namespace std;

struct FILE_TYPE {
    string name; // 파일 이름
    int startPos; // 시작 위치
    int size; // 파일 크기
};

int getID(const string& cmd) {
    vector<string> cmdList = {"write", "show", "delete", "compact", "end"};
    for (int i = 0; i < 5; i++) 
        if (cmd == cmdList[i]) 
            return i+1;
    return -1;
}


int main() {
    int v;
    cin >> v; // 최대 용량
    
    list<FILE_TYPE> disk;
    disk.push_back({"", 0, v}); // 빈 공간 노드
    
    unordered_set<string> filename;

    int remain = v;
    string cmd;

    while(cin >> cmd) {
        string name; 
        int size;

        switch (getID(cmd)) {
            case 1: { /* == write == */
                cin >> name >> size;
                
                if (filename.count(name)) { // 같은 이름의 파일이 이미 존재하면
                    cout << "error\n"; // error
                    break;
                }

                if (remain < size) { // 남은 용량보다 더 큰 파일이 들어오면
                    cout << "diskfull\n"; // diskfull
                    break;
                }

                bool found = false;

                for (auto it = disk.begin(); it != disk.end(); it++) {
                    if (it->name == "" && it->size >= size) { // 한번에 다 들어갈 수 있는 거
                        disk.insert(it, {name, it->startPos, size});

                        it->startPos += size;
                        it->size -= size;

                        if (it->size == 0) 
                            disk.erase(it);

                        found = true;
                        break;
                    }
                }

                if(!found) { // 파일 크기가 커서 나눠서 저장해야 함 
                    int left = size;

                    for (auto it = disk.begin(); it != disk.end(); it++) {
                        if (it->name != "")  // 빈 공간이 아니면
                            continue;
                        
                        int used = min(left, it->size);

                        if (used == it->size) // 빈 공간 전체를 사용함
                            it->name = name;
                        else if (used < it->size) { // 빈 공간의 일부만 사용함
                            disk.insert(it, {name, it->startPos, used}); // 새로운 파일 삽입

                            it->startPos += used; // 빈 공간 수정
                            it->size -= used;
                        }
                        
                        left -= used; // left에서 지금 파일 크기만큼 빼주기

                        if(left == 0) break;
                    }
                }

                filename.insert(name);
                remain -= size;

                break;
            }
            case 2: { /* == show == */
                cin >> name;

                if (!filename.count(name)) { // 파일이 존재하지 않으면
                    cout << "error\n"; // error
                    break;
                }

                // disk를 순회하면서 파일 이름이 name인 놈들만 startPos 출력
                for (auto it = disk.begin(); it != disk.end(); it++) 
                    if (it->name == name) 
                        cout << it->startPos << " ";
                cout << "\n";

                break;
            }
            case 3: { /* == delete == */
                cin >> name;

                if (!filename.count(name)) { // 파일이 존재하지 않으면
                    cout << "error\n"; // error
                    break;
                }

                for (auto it = disk.begin(); it != disk.end(); it++) {
                    if (it->name == name) {
                        it->name = ""; // 빈 공간으로 바꾸기
                        remain += it->size; 
                    }
                }
                filename.erase(name);
                
                for (auto it = disk.begin(); it != disk.end(); ) {
                    auto nextIt = next(it);

                    if(nextIt == disk.end()) break;

                    if (it->name == "" && nextIt->name == "") {
                        it->size += nextIt->size;
                        disk.erase(nextIt);
                    } 
                    else it++;
                }
                    
                break;
            }
            case 4: { /* == compact == */
                int pos = 0;

                for (auto it = disk.begin(); it != disk.end(); ) {
                    if (it->name != "") { // 빈 공간이 아니라 실제 파일이면
                        it->startPos = pos;
                        pos += it->size;
                        it++;
                    }
                    else it = disk.erase(it); // 빈 공간이면 -> 삭제
                }

                for (auto it = disk.begin(); it != disk.end(); ) {
                    auto nextIt = next(it);

                    if (nextIt == disk.end()) break;

                    if (it->name == nextIt->name) {
                        it->size += nextIt->size;

                        disk.erase(nextIt);
                    } 
                    else it++;
                }

                if (pos < v) 
                    disk.push_back({"", pos, v-pos});

                break;
            }
            case 5: /* == end == */
                return 0;

            default:
                break;
        }
    }
}