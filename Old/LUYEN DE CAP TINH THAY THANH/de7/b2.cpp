/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "NEN"

void hoathang(){
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ) {
        char c = s[i];
        int cnt = 0;
        while (i < n && s[i] == c) {
            cnt++;
            i++;
        }
        cout << c << cnt;
    }
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