#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <vector<long long>> g;
vector <long long> par;
vector <long long> h;
void dfs(long long u){
    for (long long x : g[u]){
        if (x != par[u]){
            par[x] = u;
            h[x] = h[u] + 1;
            dfs(x);
        }
    }
}
long long lca(long long u, long long v){
    long long d1 = 0, d2 = 0;
    if (h[v] > h[u]) return lca(v, u);
    while (h[u] >  h[v]){
        u = par[u];
        d1++;
    }
    if (u == v) return d1;
    while(u != v){
        u = par[u];
        v = par[v];
        d2 += 2;
    }
    return d1 + d2;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    while (cin >> n && n != 0){
        g.resize(n + 1);
        par.resize(n + 1, 0);
        h.resize(n + 1, 0);
        for (int i = 1; i < n; i++){
            long long u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        cin >> q;
        while (q--){
            long long x, y;
            cin >> x >> y;
            cout << lca(x, y) << ' ';
        }
        cout << endl;
    }
    return 0;
}