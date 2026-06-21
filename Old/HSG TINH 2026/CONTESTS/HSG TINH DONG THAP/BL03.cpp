/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "BL03"

int n, k;
long long res;
vector<vector<vector<long long>>> dp;

void hoathang(){
    cin >>n >> k;
    dp.resize(n + 5);
    for (int i = 0; i < n + 5; ++i){
        dp[i].resize(2);
        for (int j = 0; j < 2; ++j) {
            dp[i][j].resize(k + 5, 0);
        }
    }
    dp[1][0][1] = 1;
    dp[1][1][1] = 1;
    for (int i = 1; i < n; ++i){
        for (int j = 0; j <= 1; ++j){
            for (int l = 1; l <= k; ++l){
                if (dp[i][j][l] == 0) continue;
                dp[i + 1][1 - j][1] += dp[i][j][l];
                if (l + 1 <= k) {
                    dp[i + 1][j][l + 1] += dp[i][j][l];
                }
            }
        }
    }
    res = 0;
    for (int j = 0; j <= 1; ++j) {
        for (int l = 1; l <= k; ++l) {
            res += dp[n][j][l];
        }
    }
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
