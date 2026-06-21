#include <bits/stdc++.h>
using namespace std;
string s;
long long k, l, r;
bool check(string s){
    string s1 = s;
    reverse(s1.begin(), s1.end());
    // cerr << s1 << endl;
    return s == s1;
}
void subtask1(){
    cin >> l >> r;
    string s1 = "";
    for (int i = l - 1; i <= r - 1; i++){
        s1 += s[i];
    }
    if (check(s1)) cout << 1 << endl;
    else cout << -1 << endl;
}
bool check2(string s){
    long long l = 0, r = s.size() - 1;
    while (l <= r){
        if (s[l] != s[r]){
            return false;
        }
        l++; r--;
    }
    return true;
}
void subtask2(){
    cin >> l >> r;
    string s1 = "";
    for (int i = l - 1; i <= r - 1; i++){
        s1 += s[i];
    }
    if (check2(s1)) cout << 1 << endl;
    else cout << -1 << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s;
    cin >> k;
    long long n = s.size();
    while (k--){
        if (n <= 1000){
            subtask1();
        }
        else subtask2();
        // subtask2();
    }
    return 0;
}