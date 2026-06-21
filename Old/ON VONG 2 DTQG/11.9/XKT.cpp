#include <bits/stdc++.h>
using namespace std;
long long t;
string s;
bool dx(string s){
    int l = 0, r = s.size() - 1;
    while (l < r){
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
bool check(string x,string s){
    long long m = x.size();
    for(long long i = 0; i <= m; i++){
        string a = x.substr(0,i);
        string b = x.substr(i);
        if(s.size() >= a.size() && s.substr(s.size()-a.size()) == a && s.size() >= b.size() && s.substr(0,b.size()) == b){
            return true;
        }
    }
    return false;
}
long long xuli(string s){
    int n = s.size() - 1;
    string ans = "";
    for (int i = 0; i <= n; i++){
        for (int j = i; j <= n; j++){
            string t = s.substr(i, j - i + 1);
            if (t.size() <= ans.size()){
                continue;
            }
            if (dx(t) && check(t, s)){
                ans = t;
            }
        }
    }
    return ans.size();
}
#define task "xkt"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> s;
        cout << xuli(s) << '\n';
    }
    return 0;
}