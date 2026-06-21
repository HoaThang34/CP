#include <bits/stdc++.h>
using namespace std;
const long long MOD = 123456789;
long long n;
long long powf(long long a, long long b, long long mod){
    long long ans = 1;
    while (b != 0){
        if (b % 2 == 1){
            ans = (ans *a) % mod;
        }
        b/=2;
        a = (a*a) % mod;
    }
    return ans;
}
#define task "COUNT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    // cerr << 2 << ' ' << n << endl;
    cout << powf(2, n - 1, MOD);
    // cout << n;
    // cout << 1;
    return 0;
}