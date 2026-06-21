#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <vector<long long>> g;
vector <long long> par;
vector <long long> h;
void dfs(long long u){
    for (long long v : g[u]){
        if (v != par[u]){
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}
long long lca(long long u, long long v){
    if (h[u] < h[v]) return lca(v, u);
    while (h[u] > h[v]){
        u = par[u];
    }
    if (u == v) return u;
    while (u != v){
        u = par[u];
        v = par[v];
    }
    return v;
}
#define task "LCA"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    g.resize(n + 1);
    par.resize(n + 1, 0);
    h.resize(n + 1, 0);
    for (int i = 1; i <= n - 1; i++){   
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    cin >> q;
    dfs(1);
    while (q--){
        long long x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}