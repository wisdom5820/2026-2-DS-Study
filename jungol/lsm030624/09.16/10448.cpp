#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T;
    cin >> T;
    for (int j = 1; j<=T; j++){
        map<char, int> m;
        int i = 0;
        for (; i<26; i++){
            int val;
            cin >> val;
            m['A' + i] = val;
        }
        cin >> i;
        set<string> str;

        int sz = i;
        while (i--){
            string temp = "";
            string s;
            cin >> s;
            for (const char& c : s){
                temp = temp + to_string(m[c]);
            }
            str.insert(temp);
        }
        if (str.size() != sz){
            cout << "Case #"<< j <<": YES\n";
        }
        else{
            cout << "Case #"<< j <<": NO\n";
        }
    }
}
