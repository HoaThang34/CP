#include <bits/stdc++.h>
using namespace std;
#define task ""
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long m, n;
    cin >> m >> n;
    vector<vector<bool>> a(m + 1, vector<bool>(n + 1));
    vector<long long> u(m + 1, 0);
    vector<bool> v(n + 1, false);
    for (long long i = 1; i <= m; ++i){
        for (long long j = 1; j <= n; ++j){
            bool x; cin >> x;
            a[i][j] = x;
        }
    }
    long long ans = 0;
    for (long long i = 1; i <= m; ++i){
        for (long long j = 1; j <= n; ++j){
            if (a[i][j] && !v[j]){
                v[j] = true;
                u[i] = j;
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
    for (long long i = 1; i <= m; ++i){
        cout << u[i] << " ";
    }
    return 0;
}