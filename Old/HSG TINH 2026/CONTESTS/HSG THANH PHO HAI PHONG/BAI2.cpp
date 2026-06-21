/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BAI2"
string s;

void hoathang(){
    cin >> s;
    int ans = 0, d = 0;
    int st = 0, ed = s.size() - 1;
    for (int i = 0; i <= s.size() - 1; i++){
        if (s[i] == '1'){
            st = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--){
        if (s[i] == '1'){
            ed = i;
            break;
        }
    }
    if (st == ed){
        cout << 0 << endl;
        return;
    }
    for (int i = st; i <= ed; i++){
        if (s[i] == '0'){
            d++;
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
