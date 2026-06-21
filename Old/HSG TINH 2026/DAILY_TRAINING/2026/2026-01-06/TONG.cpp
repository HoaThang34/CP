/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
#define endl '\n'
#define nap "TONG"
int n;
long long k, p;
vector <int> a;
void sub1(){
    long long s = 0;
    for (int i = 1; i <= k; i++){
        s = (s + a[i]) % MOD;
    }
    s = s % MOD;
    cout << s << endl;
}
void sub2(){
    vector <long long> f(n + 5, 0);
    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] + a[i]) % MOD;
    long long s = ((k / n)% MOD * f[n])%MOD;
    int du = k % n;
    if (du > 0){
        long long st = (p - 1) % n + 1;
        long long ed = st + du - 1;
        if (ed <= n){
            s = (s + (f[ed] - f[st - 1]) + MOD) % MOD;
        }
        else{
            long long s1 = (f[n] - f[st - 1] + MOD) % MOD;
            long long s2 = f[ed - n];
            s = (s + s1 + s2) % MOD;
        }
    }
    cout << s << endl;
}
void hoathang(){
    cin >> n >> k >> p;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (p == 1 && k <= n){
        sub1();
    }
    else sub2();
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
