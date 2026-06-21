#include <bits/stdc++.h>
using namespace std;
const long long MOD = 30;
long long n; 
set <string> res;
void subtask1(){
    cin >> n;
    string s = to_string(n);
    sort(s.begin(), s.end());
    do{
        if (s[0] != '0') res.insert(s);
    }while(next_permutation(s.begin(), s.end()));
    long long res1 = 0;
    for (auto x : res){
        long long v = stoll(x);
        if (v % MOD == 0) res1 = max(res1, v);
    }
    if (res1 == 0) cout << -1;
    else cout << res1;
}

void subtask2(){
    string s;
    cin >> s;
    long long sum = 0;
    sort(s.rbegin(), s.rend());
    bool ck = 0;
    for (long long i = 0; i < s.size(); i++){
        if (s[i] == '0') ck = 1;
        sum += (s[i] - '0');
    }
    if (!ck || sum % 3 != 0){
        cout << -1;
        return;
    }
    cout << s;

}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    // subtask1();
    subtask2();
    return 0;
}