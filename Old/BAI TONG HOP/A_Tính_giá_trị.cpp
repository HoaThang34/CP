/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MOD = 1e6 + 7;
#define nap ""
long long n;
long long subtask1(long long n){
    long long s = 0;
    for (long long i = 1; i <= n; ++i){
        s = (s + ((i % MOD) * ((i + 1) % MOD)) % MOD) % MOD;
    }
    return s;
}
long long subtask2(long long n){
    long long s = 0;
    for (long long i = 1; i <= n; ++i){
        long long add = ((i % MOD) * ((i + 1) % MOD)) % MOD;
        s += add;
        if (s >= MOD) s -= MOD;
    }
    return s % MOD;
}
long long subtask3(long long n){
    long long a = n, b = n + 1, c = n + 2;
    if (a % 3 == 0){
        a /= 3;
    }
    else if (b % 3 == 0){
        b /= 3;
    }
    else c /= 3;
    a %= MOD;
    b %= MOD;
    c %= MOD;
    return ((a * b) % MOD * c) % MOD;
}
void hoathang(){
    cin >> n;
    if (n <= 1e3){
        cout << subtask1(n) << endl;
    }
    else if (n <= 1e6){
        cout << subtask2(n) << endl;
    }
    else cout << subtask3(n) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}