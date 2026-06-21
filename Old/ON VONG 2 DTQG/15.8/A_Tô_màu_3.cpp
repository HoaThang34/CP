#include <bits/stdc++.h>
using namespace std;
long long m, n, k;
vector<long long> a;
vector<vector<long long>> c;
vector<vector<vector<long long>>> dp;

#define task "sol"
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n >> k;
    a.resize(m + 1);
    c.resize(m + 1, vector<long long>(n + 1));
    dp.resize(m + 1, vector<vector<long long>>(n + 1, vector<long long>(k + 1, 1000000000000000000)));
    for (long long i = 1; i <= m; i++){
        cin >> a[i];
    }
    for (long long i = 1; i <= m; i++){
        for (long long j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    if (a[1] != 0) {
        dp[1][a[1]][1] = 0;
    }
    else{
        for (long long j = 1; j <= n; j++){
            dp[1][j][1] = c[1][j];
        }
    }
    for (long long i = 1; i <= m; i++){
        for (long long j = 1; j <= n; j++){
            for (long long x = 1; x <= k; x++){
                if (a[i] != 0 && a[i] != j) continue;
                long long ans = 0;
                if (a[i] == 0){
                    ans = c[i][j];
                }
                for (long long jj = 1; jj <= n; jj++){
                    if (jj == j) {
                        dp[i][j][x] = min(dp[i][j][x], dp[i-1][jj][x] + ans);
                        // cerr << dp[i-1][jj][x] + ans << endl;
                    } else if (x > 1){
                        dp[i][j][x] = min(dp[i][j][x], dp[i-1][jj][x-1] + ans);
                        // cerr << dp[i-1][jj][x-1] + ans << endl;
                    }
                }
            }
        }
    }
    long long res = 1000000000000000000;
    for (long long j = 1; j <= n; j++) {
        res = min(res, dp[m][j][k]);
        // cerr << dp[m][j][k] << ' ';
    }
    if (res == 1000000000000000000){
        cout << -1;
    }
    else{
        cout << res;
    }
    return 0;
}