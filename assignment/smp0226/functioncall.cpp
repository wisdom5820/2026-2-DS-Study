#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


struct Token {
    bool is_call;     
    char func_name;  
    string statement; 
};


struct func_info {
    char func_name; 
    size_t index;   
};

int N;
long long k1, k2;
unordered_map<char, vector<Token>> functions;

bool visited_dfs[256];
bool in_recursion_stack[256];


bool cycle(char curr) {
    visited_dfs[curr] = true;
    in_recursion_stack[curr] = true;

    if (functions.find(curr) != functions.end()) {
        for (const auto& tok : functions[curr]) {
            if (tok.is_call) {
                char next_func = tok.func_name;
                if (!visited_dfs[next_func]) {
                    if (cycle(next_func)) return true;
                } else if (in_recursion_stack[next_func]) {
                    return true;
                }
            }
        }
    }
    in_recursion_stack[curr] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> k1 >> k2)) return 0;

    for (int i = 0; i < N; i++) {
        char fun_name;
        cin >> fun_name;

        vector<Token> tokens;
        string token_str;

        while (cin >> token_str && token_str != "$") {
            if (token_str.length() == 1 && token_str[0] >= 'A' && token_str[0] <= 'Z') {
                tokens.push_back({true, token_str[0], ""});
            } else {
                tokens.push_back({false, '\0', token_str});
            }   
        }
        functions[fun_name] = tokens;
    }

    if (functions.find('M') == functions.end()) {
        cout << "NONE\nNONE\n";
        return 0;
    }

  
    if (cycle('M')) {
        cout << "DEADLOCK\n";
        return 0;
    }


    vector<string> sequence;
    stack<func_info> call_stack;

    call_stack.push({'M', 0});

    while (!call_stack.empty()) {
        func_info& top = call_stack.top();  
        char curr_func = top.func_name;
        size_t idx = top.index;

        const auto& tokens = functions[curr_func];

        if (idx >= tokens.size()) {
            call_stack.pop();
            continue;
        }

        top.index++;

        const Token& tok = tokens[idx];
        if (tok.is_call) {
            call_stack.push({tok.func_name, 0});
        } else {
            string str_seq = string(1, curr_func) + "-" + tok.statement;
            sequence.push_back(str_seq);
        }
    }

    
    long long total = sequence.size();
    long long targets[2] = {k1, k2};

    for (int i = 0; i < 2; ++i) {
        long long k = targets[i];
        long long target_idx = -1;

        if (k > 0) {
            target_idx = k - 1; 
        } else if (k < 0) {
            target_idx = total + k;
        }

        if (target_idx >= 0 && target_idx < total) {
            cout << sequence[target_idx] << "\n";
        } else {
            cout << "NONE\n";
        }
    }

    return 0;
}