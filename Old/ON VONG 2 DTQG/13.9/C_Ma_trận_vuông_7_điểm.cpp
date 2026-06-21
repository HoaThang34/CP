#include <bits/stdc++.h>
using namespace std;
long long n, x;
vector <long long> a;
vector<long long> f;
void subtask1(){
    int d = 0;
    for (long long k = 1; k <= n; k++){
        for (long long i = 1; i <= n - k + 1; i++){
            for (long long j = 1; j <= n - k + 1; j++){
                long long s1 = f[i + k - 1] - f[i - 1];
                long long s2 = f[j + k - 1] - f[j - 1];
                if (k * (s1 + s2) == x){
                    d++;
                }
            }
        }
    }
    cout << d << '\n';
}
void solve(){
    cin >> n >> x;
    a.assign(n + 1, 0);
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    subtask1();
}
#define task "SQMATRIX"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}