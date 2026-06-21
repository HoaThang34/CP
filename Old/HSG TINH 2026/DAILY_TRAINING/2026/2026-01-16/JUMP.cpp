/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define endl '\n'
#define nap "JUMP"
int n, m, d;
vector<vector<int>> a;
vector <vector<int>> dp;
void hoathang(){
    cin >> n >> m >> d;
    a.resize(n + 5, vector<int> (m + 5));
    dp.resize(n + 5, vector<int> (m + 5, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int cnt = 0;
            if (a[i][j] == 1) cnt++;
            for (int k = i - 1; k >= 1; k--){
                if (a[k][j] == 1) cnt++;
                if (cnt > d) break;
                dp[i][j] = dp[i][j] + dp[k][j];
                dp[i][j] %= MOD;
            }
            cnt = 0;
            if (a[i][j] == 1) cnt++;
            for (int k =j - 1; k >= 1; k--){
                if (a[i][k] == 1) cnt++;
                if (cnt > d) break;
                dp[i][j] = dp[i][j] + dp[i][k];
                dp[i][j] %= MOD;
            }
        }
    }
//    for (int i = 1; i <= n; i++){
//        for (int j = 1; j <= m; j++){
//            cout << a[i][j] << ' ';
//        }
//        cout << endl;
//    }
    cout << dp[n][m] << endl;
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
