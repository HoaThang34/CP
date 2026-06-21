#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s1 >> s2 >> s3;
    cout << s1 << ' ' << s2 << ' ' << s3;
    return 0;
}