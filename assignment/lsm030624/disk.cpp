/*

1. 사용한 AI (model 까지) :
    GPT-6 Astra

2. 과제에서 활용한 부분 :
    Write(), Compact() 구현이 가장 어려워보여서 부족한 구현을 매꾸기 위해서 사용을 하였습니다.

3. 어떤 도움이 필요했는지 :
    get_operation_id에서 find() 이후 그냥 반환을 하면 원하는 0, 1, 2 ,3이 제대로 나오지 않아서 it - operations.begin()를 통해 값을 바꾸었습니다.
    Write를 할 때에는 먼저 중복이 있는지, 여분 공간이 있는지, 통째로 넣을 수 있는지 순으로 파악하는 것이 좋다는 의견이 있었습니다.
    Compact의 경우에는 next()를 이용해서 end() 접근을 사전에 예방이 가능했고, 빈 공간, 즉 연속적이지 않은 file_index를 먼저 초기화 한 다음에 합치는 것을 확인하였습니다.

4. AI 제시 코드에서 추가, 개선한 부분 :
    it - operations.begin() 를 통해 인덱싱과 같은 방법으로 활용 가능, next() 함수를 통해 다음 iterator 접근 가능
*/

#include<bits/stdc++.h>

using namespace std;

struct FILE_TYPE {
    string file_name; // 이름
    int file_index; // 위치
    int file_size; // 크기
};

list<FILE_TYPE> Disk;

int get_operation_id(string operation) {
    vector<string> operations = {"write", "delete", "show", "compact"};
    auto it = find(operations.begin(), operations.end(), operation);

    if (it == operations.end()) return -1;
    return it - operations.begin();
}

void Write(string file_name, int file_size, int volume) {
    int remaining_volume = volume;

    // 중복 확인 및 전체 여유 공간 계산
    for (const auto& file : Disk) {
        if (file.file_name == file_name) {
            cout << "error\n";
            return;
        }
        remaining_volume -= file.file_size;
    }
    if (remaining_volume < file_size) {
        cout << "diskfull\n";
        return;
    }
    // 한 번에 저장할 수 있는 연속 공간 확인
    int pos = 0;

    for (auto it = Disk.begin(); ; ++it) {
        int gap_end = (it == Disk.end()) ? volume : it->file_index;
        int gap_size = gap_end - pos;

        if (gap_size >= file_size) {
            Disk.insert(it, {file_name, pos, file_size});
            return;
        }
        if (it == Disk.end()) break;
        pos = it->file_index + it->file_size;
    }

    // 연속 공간이 부족하면 나누어 저장
    pos = 0;
    int left = file_size;

    for (auto it = Disk.begin(); ; ++it) {
        int gap_end = (it == Disk.end()) ? volume : it->file_index;
        int gap_size = gap_end - pos;
        int chunk_size = min(gap_size, left);

        if (chunk_size > 0) {
            Disk.insert(it, {file_name, pos, chunk_size});
            left -= chunk_size;
        }

        if (left == 0) return;
        if (it == Disk.end()) break;
        pos = it->file_index + it->file_size;
    }
}
// 한번에 넣을 수 있는지 확인
// 안되면 분할해서 넣기

void Delete(string file_name) {
    bool found = false;

    for (auto it = Disk.begin(); it != Disk.end(); ) {
        if (it->file_name == file_name) {
            it = Disk.erase(it);
            found = true;
        } else it++;
    }

    if (!found) {
        cout << "error\n";
        return ;
    }
    return ;
}

void Show(string file_name) {
    bool found = false;

    for (const auto& file : Disk) {
        if (file.file_name == file_name) {
            if (found) cout << ' ';
            cout << file.file_index;
            found = true;
        }
    }

    if (!found) cout << "error";
    cout << '\n';
    return ;
}

void Compact() {
    int pos = 0;

    // 순서를 유지하면서 모든 조각을 앞으로 이동
    for (auto& file : Disk) {
        file.file_index = pos;
        pos += file.file_size;
    }

    // 이동 후 붙어 있는 같은 파일의 조각 합치기
    for (auto it = Disk.begin(); it != Disk.end(); ) {
        auto nxt = next(it);
        if (nxt == Disk.end()) break;

        if (it->file_name == nxt->file_name) {
            it->file_size += nxt->file_size;
            Disk.erase(nxt);
            // it을 유지하여 다음 조각도 같은 이름인지 확인
        } else it++;

    }

    return ;
}

int main() {
    string file_name, operation;
    int file_size, volume;

    cin >> volume;

    while (cin >> operation) {
        if (operation == "end") break;

        int operation_id = get_operation_id(operation);

        if (operation_id != 3) cin >> file_name;
        if (operation_id == 0) cin >> file_size;

        switch (operation_id) {
        case 0:
            Write(file_name, file_size, volume);
            break;
        case 1:
            Delete(file_name);
            break;
        case 2:
            Show(file_name);
            break;
        case 3:
            Compact();
            break;
        default:
            return 0;
        }
    }
}
