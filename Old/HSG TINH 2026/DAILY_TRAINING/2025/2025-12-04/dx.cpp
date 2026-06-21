/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
string s;
void hoathang(){
    cin >> s;
    int d = 0;
    for (int i = 0; i <= s.size() - 1; i++){
        string ans = "";
        for (int j = i; j <= s.size() - 1; j++){
            ans += s[j];
            if (ans == "virus"){
                d++;
            }
        }
    }
    cout << d << endl;
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
