/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "MAYMAN"
#define int long long
int a, b, c;
void hoathang(){
    cin >> a >> b >> c;
    int du = (a + b) %10;
    if (du % c == 0) cout << du << endl;
    else cout << du % c << endl;
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
