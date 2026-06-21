/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int p[100005];

int find(int i) {
    if (p[i] == i) return i;
    return p[i] = find(p[i]);
}

bool unite(int i, int j) {
    int r1 = find(i);
    int r2 = find(j);
    if (r1 != r2) {
        p[r1] = r2;
        return true;
    }
    return false;
}

void hoathang() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e.begin(), e.end(), cmp);

    for (int i = 1; i <= n; i++) p[i] = i;

    long long res = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (unite(e[i].u, e[i].v)) {
            res += e[i].w;
            cnt++;
        }
    }

    if (cnt == n - 1) cout << res << endl;
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