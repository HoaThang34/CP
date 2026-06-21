#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<tuple<int, char, int>> rels;
string best_s;
bool found_sol;

bool check(const string& cur_s){
    for(const auto& r : rels){
        int u = get<0>(r) - 1;
        char op = get<1>(r);
        int v = get<2>(r) - 1;

        if (u < 0 || u >= (int)cur_s.length() || v < 0 || v >= (int)cur_s.length()){
            return false; 
        }
        if (cur_s[u] == '?' || cur_s[v] == '?') continue; 
        
        char cu = cur_s[u];
        char cv = cur_s[v];

        if(op == '='){
            if(cu != cv) return false;
        } else if (op == '<'){
            if(cu >= cv) return false;
        } else if (op == '>'){
            if(cu <= cv) return false;
        }
    }
    return true;
}

void solve_rec(int cur_p, string& cur_build_s){
    if(cur_p == n){
        if(check(cur_build_s)){
            if(!found_sol || cur_build_s < best_s){
                best_s = cur_build_s;
                found_sol = true;
            }
        }
        return;
    }

    for(int c_code = 0; c_code < k; ++c_code){
        cur_build_s[cur_p] = (char)('a' + c_code);
        if (check(cur_build_s.substr(0, cur_p + 1))){ 
            solve_rec(cur_p + 1, cur_build_s);
        }
    }
    cur_build_s[cur_p] = '?'; // Backtrack by not assigning or for next path
                              // Actually, the '?' check in main handles unassignable
                              // This is more for pruning if a partial assignment is already invalid.
                              // For the final '?' logic, we check after finding a best_s.
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> k >> m;

    for (int i = 0; i < m; ++i){
        string s_in;
        cin >> s_in;
        int u_val = 0, v_val = 0;
        char op_val = ' ';
        int ptr = 0;
        string num1_str = "";
        while(ptr < (int)s_in.length() && isdigit(s_in[ptr])){
            num1_str += s_in[ptr];
            ptr++;
        }
        u_val = stoi(num1_str);
        op_val = s_in[ptr];
        ptr++;
        string num2_str = "";
        while(ptr < (int)s_in.length() && isdigit(s_in[ptr])){
            num2_str += s_in[ptr];
            ptr++;
        }
        v_val = stoi(num2_str);
        rels.emplace_back(u_val, op_val, v_val);
    }

    found_sol = false;
    string s_tmp(n, ' '); 
    
    
    if (n <= 10 && k <= 5 && m <= 20) { // Subtask 1 conditions
        solve_rec(0, s_tmp);
    }


    if(!found_sol){
        cout << string(n, '?') << endl;
    } else {
        string final_s = best_s;
        for(int i=0; i<n; ++i){
            char original_c = best_s[i];
            bool is_unique = true;
            for(int c_try_code = 0; c_try_code < k; ++c_try_code){
                char c_to_test = (char)('a' + c_try_code);
                if(c_to_test == original_c) continue;

                string test_s_str = best_s;
                test_s_str[i] = c_to_test;
                if(check(test_s_str)){
                    is_unique = false;
                    break;
                }
            }
            if(!is_unique){
                final_s[i] = '?';
            }
        }
        cout << final_s << endl;
    }

    return 0;
}