#include <bits/stdc++.h>
using namespace std;
long long m, n, u, v, k;
vector <vector <bool>> a;
vector <vector<long long>> pre;

void prefixfum(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == true){
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + 1;
            }
            else{
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + 0;
            }
        }
    }
}
void nhap(){
    cin >> m >> n >> k >> u >> v;
    a.resize(m + 1, vector <bool> (n + 1, false));
    pre.resize(m + 1, vector <long long> (n + 1, 0));
    for (int i = 1; i <= k; i++){
        long long x, y;
        cin >> x >> y;
        a[x][y] = true;
    }
}
void solve(){
    long long ans = 0;
    prefixfum();
    long long k = u;
    while (k <= n){
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                long long i1 = i + k;
                long long j1 = j + k;
                if (i1 <= m && j1 <= n){
                    long long sum = (pre[i1][j1] - pre[i - 1][j1] - pre[i1][j - 1] + pre[i - 1][j - 1]);
                    if (sum <= v){
                        ans = max(ans, k);
                    }
                }
            }
        }
        k = k + u;
    }
    cout << ans;
}
#define nap "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    nhap();
    solve();
    return 0;
}
