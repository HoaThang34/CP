#include <bits/stdc++.h>
using namespace std;
long long n;
const long long N = 1e6 + 7;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (long long i = 2; i <= sqrt(N); i++){
        if (f[i]){
            for (long long j = i*i; j <= N; j+=i){
                f[j] = false;
            }
        }
    }
}
void solve(){
    sang();
    long long d = 0;
    for (int i = 2; i <= n; i++){
        if (f[i]){
            d++;
        }
    }
    d += sqrt(n) - 1;
    cout << d;
}
#define task "number"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    solve();
    return 0;
}