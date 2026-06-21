#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <long long>> dp;
#define task "DUONGDI"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    dp.resize(n + 1, vector <long long> (n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (i > 1) dp[1][j] = 1;
            if (j > 1) dp[i][1] = 1;
            if (i > 1 && j > 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][n];   
    return 0;
}