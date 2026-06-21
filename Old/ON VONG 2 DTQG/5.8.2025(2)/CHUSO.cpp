#include <bits/stdc++.h>
using namespace std;
string s;
long long n, m;
void subtask1(){
    string s1 = s;
    reverse (s1.begin(), s1. end());
    s = s + s1;
    n--;
    while (n--){
        s = s + s;
    }
    cout << s[m - 1];
}
void subtask2(){
    long long k = s.size();
    while (n--){
        k += k;
    }
    if (k < m) cout << -1;
    else{
        m--;
        long long pos = m % s.size();
        long long p = m/s.size();
        if (p % 2 == 0){ // xuoi
            cout << s[pos];
        }
        else{ //nguoc
            reverse(s.begin(), s.end());
            cout << s[pos];
        }
    }
}
#define task "CHUSO"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s;
    cin >> n >> m;
    // subtask1();
    subtask2();
    return 0;
}