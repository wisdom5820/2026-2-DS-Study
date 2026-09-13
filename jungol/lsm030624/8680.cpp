#include<bits/stdc++.h>

using namespace std ;

int main () {
    vector<char> str;
    vector<char> check;
    int N;

    cin >> N;
    int idx = 0;
    for (; idx<N; idx++){
        char c;
        cin >> c;
        str.push_back(c);
    }
    int err = 0;
    if ((N == 1) && (str[0] == '(')){
        cout << 0;
        return 0;
    }
    else if ((N == 1) && (str[0] == ')')){
        cout << 1;
        return 0;
    }
    for (idx = 0; idx < N; idx++){

        if (str[idx] == '('){
            check.push_back('(');
        }
        else if (str[idx] == ')'){
            if (check.size() > 0){
                if (check.back() == '('){
                    check.pop_back();
                }
                else{
                    check.pop_back();
                    check.push_back('(');
                    err++;
                }
            }
            else{
                check.push_back('(');
                err++;
            }
        }
    }
    cout << err;
}
