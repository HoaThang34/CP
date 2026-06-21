/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "BL04"

int m, n, t;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> a, v;

bool check(int k) {
    t++;
    queue<pair<int, int>> q;
    q.push({1, 1});
    v[1][1] = t;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == m && y == n) {
            return 1;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && v[nx][ny] != t) {
                if (abs(a[x][y] - a[nx][ny]) <= k) {
                    v[nx][ny] = t;
                    q.push({nx, ny});
                }
            }
        }
    }
    return 0;
}

void hoathang() {
    cin >> m >> n;
    a.resize(m + 5);
    v.resize(m + 5);
    for (int i = 1; i <= m; ++i) {
        a[i].resize(n + 5);
        v[i].resize(n + 5, 0);
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    int l = 0;
    int r = 1e9;
    int res = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")) {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
