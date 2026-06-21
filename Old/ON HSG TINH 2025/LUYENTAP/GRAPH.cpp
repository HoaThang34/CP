/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "graph"

int n, m;
vector<vector<int>> g;
vector<int> d, l;
vector<bool> ap;
vector<int> res;
vector<bool> vs;
int t;
int cnt;

void dfs(int u, int p) {
    vs[u] = true;
    d[u] = l[u] = ++t;
    int ch = 0;
    for (int v : g[u]) {
        if (v == p) {
            continue;
        }
        if (vs[v]) {
            l[u] = min(l[u], d[v]);
        } else {
            ch++;
            dfs(v, u);
            l[u] = min(l[u], l[v]);
            if (p != 0 && l[v] >= d[u]) {
                ap[u] = true;
                res[u]++;
            }
        }
    }
    if (p == 0 && ch > 1) {
        ap[u] = true;
        res[u] = ch;
    } else if (p != 0 && ap[u]) {
        res[u]++;
    }
}

void hoathang(){
    cin >> n >> m;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    d.resize(n + 5, 0);
    l.resize(n + 5, 0);
    ap.resize(n + 5, false);
    res.resize(n + 5, 0);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt = 0;
    t = 0;
    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            cnt++;
            dfs(i, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ap[i]) {
            cout << cnt - 1 + res[i] << endl;
        } else {
            if (g[i].empty()) {
                cout << cnt - 1 << endl;
            } else {
                cout << cnt << endl;
            }
        }
    }
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
