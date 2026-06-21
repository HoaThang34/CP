/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "GAME"
string s;
void hoathang(){
    cin >> s;
    unordered_map<int, int> cnt;
    for (char x : s){
        cnt[x]++;
    }
    int d1 = min(cnt['L'], cnt['R']);
    int d2 = min(cnt['U'], cnt['D']);
    if (d1 == 0 && d2 == 0){
        cout << -1 << endl;
    }
    else if (d1 == 0 || d2 == 0){
        cout << 2 << endl;
    }
    else cout << 2*(d1 + d2) << endl;
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
