/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DFSSECUR"
int n, m, s, k;
vector <vector <int>> g;
vector<int> par;
vector <bool> vs;
void dfs(int u, int p){
    par.push_back(u);
    if (u != s){
        for (int i = par.size() - 1; i >= 0; i--){
            cout << par[i] << ' ';
        }
        cout << endl;
    }
    sort(g[u].begin(), g[u].end());
    for (int v : g[u]) {
        if (v != p && !vs[v]) {
            dfs(v, u);
        }
    }
    par.pop_back();
}
void hoathang(){
    cin >> n >> m >> s >> k;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        if (x >= 1 && x <= n)
            vs[x] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (s < 1 || s > n || vs[s]) {
        cout << -1 << endl;
        return;
    }
    dfs(s, -1);
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
