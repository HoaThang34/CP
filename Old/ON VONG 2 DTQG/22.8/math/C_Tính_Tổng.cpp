#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long t, n, k;
long long binpow(long long a, long long b, long long mod){
    long long res = 1;
    a = a % mod;
    while (b > 0){
        if (b % 2 == 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b/=2;
    }
    return res;
}
void subtask1(){
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans = (ans + binpow(i, k, MOD)) % MOD;
    }
    cout << ans << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> n >> k;
        subtask1();
    }    
    return 0;
}