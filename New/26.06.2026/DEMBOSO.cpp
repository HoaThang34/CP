/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define nap "DEMBOSO"
#define endl '\n'
#define int long long
int n, k;
vector <vector<int>> dp;
void hoathang(){
    cin >> n>> k;
    dp.resize(k + 5, vector<int> (n + 5));
    for (int i = 1; i <= n; i++){
        dp[1][i] = 1;
    }
    for (int i = 1; i < k; i++){
        for (int j = 1; j <= n; j++){
            if (!dp[i][j]) continue;
            for (int t =j; t <= n; t += j){
                dp[i + 1][t] += dp[i][j];
                dp[i + 1][t] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
