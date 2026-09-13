#include<bits/stdc++.h>

using namespace std ;

int main () {

    vector<char> pw;
    int T;
    cin >> T;

    string s;
    int i =0;

    for (; i < T; i++){
        cin >> s;
        int idx= 0;
        int it;
        for (int itr = 0; itr<s.size(); itr++){
            if (s[itr] == '<'){
                if (idx > 0){
                    idx--;
                }
            }
            else if (s[itr] == '>'){
                if ((idx >= 0) && (idx < pw.size())){
                    idx++;
                }
            }
            else if (s[itr] == '-'){
                if (idx > 0){
                    pw.erase(pw.begin() + idx - 1);
                    idx--;
                }

            }
            else{
                pw.insert(pw.begin() + idx, s[itr]);
                idx++;
            }

        }
        it = 0;
        for (; it<pw.size(); it++){
            cout << pw[it];
        }
        cout << endl;
        pw.clear();
    }
}
