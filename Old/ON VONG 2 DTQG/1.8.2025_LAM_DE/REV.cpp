#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> a;
vector<pair<int, char>> p;
string s1 = "";
string ans = "";
#define task "REV"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    getline(cin, s);
    if(!s.empty() && s.back() == '.'){
        s.pop_back();
        if(!s.empty() && s.back() == ' '){
            s.pop_back();
        }
    }
    for(int i = 0; i <= s.length(); i++){
        if(i == s.length() || s[i] == ' ' || s[i] == ',' || s[i] == '.'){
            if(!s1.empty()){
                a.push_back(s1);
                s1 = "";
            }
            if(i < s.length() && (s[i] == ',' || s[i] == '.')){
                p.push_back({a.size() - 1, s[i]});
            }
        }
        else{
            s1 += s[i];
        }
    }
    for(int i = 0; i < p.size(); i++){
        p[i].first = a.size() - 2 - p[i].first;
    }
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        if(i > 0) ans += " ";
        ans += a[i]; 
        for(int j = 0; j < p.size(); j++){
            if(p[j].first == i){
                ans += p[j].second;
            }
        }
    }
    if(ans.back() != '.'){
        ans += ".";
    }
    if(!ans.empty()){
        ans[0] = toupper(ans[0]);
    }
    for(int i = 0; i < ans.length() - 1; i++){
        if(ans[i] == '.' && i + 1 < ans.length() && ans[i+1] == ' '){
            for(int j = i + 2; j < ans.length(); j++){
                if(ans[j] != ' '){
                    ans[j] = toupper(ans[j]);
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}