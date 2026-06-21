#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>> a;
vector<vector<long long>> dp;
vector<vector<int>> trace;
#define task "TRIANNUM"
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1, vector<long long>(n + 1));
    dp.resize(n + 1, vector<long long>(n + 1, 0));
    trace.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                trace[i][j] = j;
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
                trace[i][j] = j - 1;
            }
            else {
                if (dp[i - 1][j - 1] > dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + a[i][j];
                    trace[i][j] = j - 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                    trace[i][j] = j;
                }
            }
        }
    }
    long long res = 0;
    int pos = 1;
    for (int j = 1; j <= n; j++) {
        if (dp[n][j] > res) {
            res = dp[n][j];
            pos = j;
        }
    }
    vector<int> path;
    int row = n, col = pos;
    while (row >= 1) {
        path.push_back(a[row][col]);
        col = trace[row][col];
        row--;
    }
    reverse(path.begin(), path.end());
    cout << res << '\n';
    for (long long x : path) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
