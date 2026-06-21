/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "duongdep"

int n;
long long k;
vector<long long> a, f;
map<long long, int> cnt;

void hoathang() {
    cin >> n >> k;
    a.resize(n + 5);
    f.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 0;
    cnt[0] = 0;
    int rmax = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i] - k;
        if (cnt.count(f[i])) {
            int len = i - cnt[f[i]];
            if (len > rmax) {
                rmax = len;
                ans = cnt[f[i]] + 1;
            }
        } else {
            cnt[f[i]] = i;
        }
    }
    if (rmax == 0) {
        cout << 0 << endl;
    } else {
        cout << ans << " " << rmax << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")) {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
