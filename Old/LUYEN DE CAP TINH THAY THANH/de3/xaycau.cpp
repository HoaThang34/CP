/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

struct e {
    int u, v;
    long long w;
};

bool cmp(e a, e b) {
    return a.w < b.w;
}

int p[100005];

int f(int i) {
    if (p[i] == i) return i;
    return p[i] = f(p[i]);
}

void hoathang() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<e> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].u >> a[i].v >> a[i].w;

    sort(a.begin(), a.end(), cmp);

    for (int i = 1; i <= n; i++) p[i] = i;

    long long s = 0;
    int c = 0;
    for (int i = 0; i < m; i++) {
        int r1 = f(a[i].u);
        int r2 = f(a[i].v);
        if (r1 != r2) {
            p[r1] = r2;
            s += a[i].w;
            c++;
        }
    }

    if (c == n - 1) cout << s << endl;
    else cout << -1 << endl;
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