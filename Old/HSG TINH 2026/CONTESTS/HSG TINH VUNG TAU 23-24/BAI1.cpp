/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 2023;
#define endl '\n'
#define nap "BAI1"
long long n;
void hoathang(){
    cin >> n;
    long long n1 = n % MOD;
    long long n2 = (3*n + 1) % MOD;
    if (n1 % 2 == 0) n1/=2;
    else n2/=2;
    long long ans = (n1*n2)%MOD;
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
