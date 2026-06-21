#include <bits/stdc++.h>
using namespace std;
#define task "sum"
const long long MOD = 1e9 + 7;

long long n;
vector<long long> a;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n;
    a.resize(n + 1);
    for (long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<long long> ps(n + 1, 0);
    for (long long i = 1; i <= n; i++){
        ps[i] = ps[i - 1] + a[i];
    }
    long long s = 0;
    for (long long i = 1; i <= n; i++){
        for (long long j = i; j <= n; j++){
            long long t = ps[j] - ps[i - 1];
            s = (s + t * t % MOD) % MOD;
        }
    }

    cout << s;
    return 0;
}
