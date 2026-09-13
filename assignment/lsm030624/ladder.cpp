#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main() {
    int K;
    cin >> K;
    cin.ignore();
    
    vector<vector<int>> int_int_list(21, vector<int>(1001, 0));
    string str;
    int itr = 1;

    int idx;

    vector<int> int_list(1001, 0);

    while(itr < K) {
        getline(cin, str);
        stringstream ss(str);
        while (ss >> idx) {
 
            if (idx >= 0)
                int_int_list[itr][idx] = 1;
        }

        itr++;
    }

    idx = 0;
    
    
    while (idx < K) {
        itr = idx;
        int depth = 0;
        while (depth < 1001) {
            if (int_int_list[idx][depth] > int_int_list[idx+1][depth])
                idx--;
            else if (int_int_list[idx][depth] < int_int_list[idx+1][depth])
                idx++;
            depth++;
        }
        int_list[idx] = 'a' + itr;
        idx = itr + 1;
    }
    idx = 0;
    while (idx < K) {
        cout << char(int_list[idx]) << " ";
        idx++;
    }
}