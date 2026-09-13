#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, k;
    cin >> T >> k;
    for (int i =0; i<T; i++){
        int N;
        string S;
        cin >> N;
        cin >> S;
        stack<char> ans;
        int check = 0;
        int j = N-1;
        for (; j >= 0; j--){
            if (check % 2 == 0){
                if (S[j] == 'M'){
                    ans.push('M');
                }
                else{
                    ans.push('O');
                    check++;
                }
            }
            else{
                if (S[j] == 'M'){
                    ans.push('O');
                    check++;
                }
                else{
                    ans.push('M');
                }
            }
        }
        cout << "YES" <<endl;
        if (k == 1){
            for (j = 0; j<N; j++){
                cout << ans.top() << "";
                ans.pop();
            }
            cout<<endl;
        }

    }
}
