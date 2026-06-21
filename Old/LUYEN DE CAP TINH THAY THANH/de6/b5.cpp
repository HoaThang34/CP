/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang() {
    int n;
    long long s;
    if (!(cin >> n >> s)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, res = n + 1;
    long long sum = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum >= s) {
            res = min(res, r - l + 1);
            sum -= a[l];
            l++;
        }
    }

    if (res > n) cout << 0 << endl;
    else cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")) {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}