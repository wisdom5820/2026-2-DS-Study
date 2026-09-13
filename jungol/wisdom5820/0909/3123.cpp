#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;


int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // getline 쓰기 전 남아있는 개행문자 처리
    
    for(int i = 0; i < N; i++) {
        vector<char> v;
        string s;
        getline(cin, s);

        vector<char>::iterator it = v.begin();
        int strlen = s.size();
        for(int j = 0; j < strlen; j++) {
            char c = s[j];

            if(c == '>' && !v.empty() && it != v.end()) it++;
            else if(c == '<' && !v.empty() && it != v.begin()) it--;
            else if(c == '-' && !v.empty() && it != v.begin()) {
                it = v.erase(it - 1); 
                // it는 삭제할 원소의 다음 원소 iterator를 받음
                // 만약에 벡터에 원소가 하나 있으면 it == v.end() 
            } else if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                it = v.insert(it, c) + 1;
                // it = v.insert(iterator, value)
                // iterator 자리에 value를 넣고, 나머지 원소들은 한 칸씩 밀려남
                // it는 value의 iterator를 받음
            }
        }

        for(char c : v) cout << c;
        cout << '\n';
    }
    return 0;
}