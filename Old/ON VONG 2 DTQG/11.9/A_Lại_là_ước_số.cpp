#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long l, r;
vector <long long> f(N, 0);
void sang(){
    for (long long i = 1; i <= N; i++){
        for (long long j = i; j <= N; j+=i){
            f[j] += i;
        }
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    sang();
    cin >> l >> r;
    long long s = 0;
    for (long long i = l; i <= r; i++){
        s += f[i];
        // cerr << s << '\n';
    }
    cout << s;
    return 0;
}