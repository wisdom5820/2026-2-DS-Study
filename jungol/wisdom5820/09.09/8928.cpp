#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, k;
    cin >> T >> k;

    while(T--) {
        int n;
        string s;
        cin >> n >> s;

        cout << "YES\n";

        if(k == 1) {
            string for_moo(n, ' '); 
            bool flip = false;

            for(int i = n-1; i >= 0; i--) { // 문자열 역순으로 검사
                if(flip) 
                    s[i] = (s[i] == 'M') ? 'O' : 'M';

                for_moo[i] = s[i];

                if(s[i] == 'O') 
                    flip = !flip; // 마지막 문자가 'O'일 때만 flip 바꾸기
            }
            
            cout << for_moo << '\n';
        }
    }


    return 0;
}