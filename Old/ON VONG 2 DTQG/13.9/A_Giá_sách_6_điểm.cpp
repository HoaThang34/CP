#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long n, l;
vector<long long> h, w;
#define task "BOOKS"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> l;
    h.assign(n + 1, 0);
    w.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> h[i] >> w[i];
    }
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        long long w = 0;
        long long rmax = 0;
        for(int j = i; j >= 1; j--){
            w += w[j];
            rmax = max(rmax, h[j]);
            if(w <= l){
                if (j > 1){
                    dp[i] = min(dp[i], dp[j - 1] + rmax);
                }
                else{
                    dp[i] = min(dp[i], 0 + rmax);
                }
            } else{
                break;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}