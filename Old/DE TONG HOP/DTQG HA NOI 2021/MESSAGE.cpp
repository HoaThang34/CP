#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long n, m;
vector<vector<long long>> c;
#define task "MESSAGE"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    c.resize(n + 1, vector<long long>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INF));
    vector<vector<long long>> tr(m + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i-1][j];
            tr[i][j] = 0;
            for(int p = 1; p <= j; p++){
                if(dp[i-1][j-p] != INF){
                    long long cur = dp[i-1][j-p] + c[p][i];
                    if(cur < dp[i][j]){
                        dp[i][j] = cur;
                        tr[i][j] = p;
                    }
                }
            }
        }
    }
    cout << dp[m][n] << '\n';
    vector<long long> ans(m + 1);
    long long cur_n = n;
    for(int i = m; i >= 1; i--){
        long long p = tr[i][cur_n];
        ans[i] = p;
        cur_n -= p;
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}