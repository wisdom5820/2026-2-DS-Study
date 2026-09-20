#include <iostream>
#include <sstream>
#include <string>
#include <map> // 정렬이 필요하니까
using namespace std;

int main() {

    string s;
    map<string, int> m;
    bool next = false;

    while(getline(cin, s)) {
        if(s == "------") {
            next = true;
            continue;
        } 
        else if(s == "======") {
            break;
        }

        stringstream ss(s);    

        int a, b;
        string name;
        ss >> a >> b >> name;

        if(!next) m[name] -= (b - a);
        else      m[name] += (b - a);
    }
    
    bool nodiff = true;
    for(const auto& [name, diff] : m) {
        if(diff == 0) continue;

        cout << name << ' ';
        if(diff > 0) cout << '+';
        cout << diff << '\n';

        nodiff = false;
    }
        
    if(nodiff) cout << "No differences found.\n";
    
    return 0;
}