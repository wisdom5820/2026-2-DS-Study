#include <iostream>
#include <string>

using namespace std;

int main(){
    string str[5];

    for(int i = 0; i < 5; i++){
        cin >> str[i];
    }

    // 각 줄 단어의 최대 길이는 15글자
    for(int i = 0; i < 15; i++){ // 열 (세로 위치)
        for(int j = 0; j < 5; j++){ // 행 (줄 번호)
            // j번째 문자열의 길이가 현재 위치(i)보다 클 때만 출력
            if(i < str[j].length()){
                cout << str[j][i];
            }
        }
    }

    return 0;
}