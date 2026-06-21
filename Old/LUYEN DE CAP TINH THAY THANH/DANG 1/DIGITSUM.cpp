/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DIGITSUM"
string s;
string sum(string s){
    long long ans = 0;
    for (char x : s){
        int d = x - '0';
        ans += d;
    }
    return to_string(ans);
}
void hoathang(){
    cin >> s;
    while (s.size() > 1){
        s = sum(s);
    }
    cout << s << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
