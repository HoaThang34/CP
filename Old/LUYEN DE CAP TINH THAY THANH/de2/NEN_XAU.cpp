/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "NENDULIEU" 

void hoathang(){
    string s;
    if (!(cin >> s)) return;
    
    int n = s.length();
    if (n == 0) return;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            cout << cnt << s[i-1];
            cnt = 1;
        }
    }
    // In nhom ky tu cuoi cung
    cout << cnt << s[n-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}