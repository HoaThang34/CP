/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU4"
string s;

void hoathang(){
    cin >> s;
    int d = 0;
    for (char x : s){
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            d++;
        }
    }
    int d2 = s.size() - d;
    int ans = d*d2;
    cout << ans << endl;
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
