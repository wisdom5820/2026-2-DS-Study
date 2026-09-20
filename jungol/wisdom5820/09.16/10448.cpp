#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int T; // test case
    cin >> T;

    vector<char> alphabet(26);
    for(int t = 1; t <= T; t++) {
        for(int i = 0; i < 26; i++) { // alphabet -> digit
            char d;
            cin >> d;
            alphabet[i] = d;
        }

        int N; // 인코딩 단어 목록 수
        cin >> N;

        unordered_map<string, int> m;
        while(N--) {
            string word, encoding = "";
            cin >> word;
            for(const char c : word) 
                encoding += alphabet[c - 'A']; // encoding
            
            m[encoding]++; // 맵에 추가
        }

        bool dup = false; // 중복이 있는지 확인
        for(const auto& [encoding, cnt] : m) {
            if(cnt > 1) dup = true; // 1개 이상이 있다 -> 중복
        }

        if(dup) cout << "Case #" << t << ": YES\n";
        else    cout << "Case #" << t << ": NO\n";
    }

    return 0;
}