/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "bai1"
long long a, b, k;

void hoathang(){
    cin >> a >> b >> k;
    bool ok = false;
    if (k % 2 == 1) k = k/2 + 1;
    else{
        ok = true;
        k = k/2;
    }
    long long ans;
    if (ok == false)
        ans = (a*k) - (b*(k - 1));
    else
        ans = (a*k) - (b*k);
//    cerr << k << endl;
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
