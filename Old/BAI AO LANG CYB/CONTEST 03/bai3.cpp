/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
long long n;
void hoathang(){
    cin >> n;
    long long lt = 5, ans = 0;
    while (lt <= n){
        ans += n/lt;
        lt*=5;
    }
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
