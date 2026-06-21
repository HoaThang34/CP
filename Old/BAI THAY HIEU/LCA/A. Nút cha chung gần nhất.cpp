#include <bits/stdc++.h>
using namespace std;
long long n, k, m;
vector <vector<long long>> g;
vector <long long> par;
vector <long long> h;
void dfs(long long u){
    for (long long x : g[u]){
        if (x != par[u]){
            h[x] = h[u] + 1;
            par[x] = u;
            dfs(x);
        }
    }
}
long long lca(long long u, long long v, long long k){
    if (h[v] > h[u]) return lca(v, u, k);
    while (h[u] > h[v]){
        u = par[u];
        // cerr << u << endl;
    }
    if (u == v) return u;
    while(u != v){
        u = par[u];
        v = par[v];
    }
    return v;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k >> m;
    g.resize(n + 1);
    par.resize(n + 1, 0);
    h.resize(n + 1, 0);
    for (int i = 1; i <= n - 1; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(k);
    while (m--){
        long long u, v;
        cin >> u >> v;
        cout << lca(u, v, k) << endl;
    }
    return 0;
}