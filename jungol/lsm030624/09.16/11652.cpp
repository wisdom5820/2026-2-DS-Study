# include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> m;
    string str;

    int i;
    string st;
    while (1) {
        pair<int, string> p(0, "");
        getline(cin, str);
        if (str == "------") {
            break;
        }
        stringstream ss(str);
        int iter = 0;
        while (ss >> st) {
            int temp;
            if (iter == 0) {
                temp = stoi(st);
                p.first = p.first - temp;
            } else if (iter == 1) {
                temp = stoi(st);
                p.first = p.first + temp;
            } else {
                p.second = st;

            }
            iter++;
        }


        m[p.second] -= p.first;
    }

    while (1) {
        pair<int, string> p(0, "");
        getline(cin, str);
        if (str == "======") {
            break;
        }

        stringstream ss(str);
        int iter = 0;

        while (ss >> st) {
            int temp;
            if (iter == 0) {
                temp = stoi(st);
                p.first = p.first - temp;
            } else if (iter == 1) {
                temp = stoi(st);
                p.first = p.first + temp;
            } else {
                p.second = st;

            }
            iter++;
        }

        m[p.second] += p.first;
    }

    i = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second < 0) {
            cout << itr->first << " " << itr->second << "\n";
            i++;
        } else if (itr->second > 0) {
            cout << itr->first << " +" << itr->second << "\n";
            i++;
        }
    }
    if (i == 0) {
        cout << "No differences found.";
    }
}
