/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

struct Canh {
    int u, v, w;
};

bool ss(Canh a, Canh b) {
    return a.w < b.w;
}

int p[100005];

int tim(int i) {
    if (p[i] == i) return i;
    return p[i] = tim(p[i]);
}

bool hop(int i, int j) {
    int r1 = tim(i);
    int r2 = tim(j);
    if (r1 != r2) {
        p[r1] = r2;
        return true;
    }
    return false;
}

void hoathang() {
    int n, m1, m2;
    if (!(cin >> n >> m1 >> m2)) return;
    
    for (int i = 1; i <= n; i++) p[i] = i;
    
    int d = 0;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        if (hop(u, v)) d++;
    }
    
    vector<Canh> ds(m2);
    for (int i = 0; i < m2; i++) {
        cin >> ds[i].u >> ds[i].v >> ds[i].w;
    }
    
    sort(ds.begin(), ds.end(), ss);
    
    long long ans = 0;
    for (int i = 0; i < m2; i++) {
        if (hop(ds[i].u, ds[i].v)) {
            ans += ds[i].w;
            d++;
        }
    }
    
    if (d == n - 1) cout << ans << endl;
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