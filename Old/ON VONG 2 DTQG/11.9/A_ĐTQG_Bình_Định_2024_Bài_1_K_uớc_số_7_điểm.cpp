#include <bits/stdc++.h>
using namespace std;
long long q, n, m, k;
const int N = 100005;
const int K = 16;
vector<int> f(N, 0);
vector<vector<int>> ans(K + 1, vector<int>(N, 0));
void pre(){
    vector<int> pf(N);
    for(int i = 0; i < N; i++) pf[i] = i;
    for (int i = 2; i * i < N; i++){
        if (pf[i] == i){
            for (int j = i * i; j < N; j += i){
                if (pf[j] == j){
                    pf[j] = i;
                }
            }
        }
    }
    f[1] = 0;
    for (int i = 2; i < N; i++){
        f[i] = f[i / pf[i]] + 1;
    }
    for (int i = 1; i <= K; i++){
        for (int j = 1; j < N; j++){
            ans[i][j] = ans[i][j-1];
            if (f[j] == i){
                ans[i][j]++;
            }
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    cout << ans[k][m] - ans[k][n - 1] << '\n';
}
#define task "kdiv"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    pre();
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}