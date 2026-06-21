#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long n, m;
vector <long long> A, B;
long long a = 1, b = 1;
long long gcd(long long a, long long b){
    long long c;
    while (b > 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
#define task "PGCD"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    A.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> A[i];
        a *= A[i];
    }
    cin >> m;
    B.resize(m + 1);
    for (int i = 1; i <= m; i++){
        cin >> B[i];
        b *= B[i];
    }
    // cerr << a << ' ' << b;
    cout << gcd(a, b) % MOD;
    return 0;
}