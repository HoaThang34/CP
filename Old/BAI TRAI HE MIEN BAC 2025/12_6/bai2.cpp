#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
#define task "sol"

int n, m, k;
int a[4005][4005];
long long f[4005][4005];

long long get(int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            while (i + res <= n && j + res <= m && get(i, j, i + res, j + res) <= k) {
                ++res;
            }
        }
    }

    cout << res << "\n";
    return 0;
}
