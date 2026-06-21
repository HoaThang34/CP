/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 20240131;
#define endl '\n'
#define nap "FACTORIAL"
long long n;
void hoathang(){
    cin >> n;
    long long s = 1, ans = 0;
    if (n < MOD){
        for (int i = 1; i <= n; i++){
            s = (s*i)%MOD;
            ans = (ans + s) % MOD;
        }
    }
    else{
        for (int i = 1; i <= MOD; i++){
            s = (s*i)%MOD;
            ans = (ans + s) % MOD;
        }
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
