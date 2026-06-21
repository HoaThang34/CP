#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> w;
vector <long long> par;
void dfs(long long u){
    vs[u] = true;
    for (long long x : g[u]){
        if (!vs[x]){
            par[x] = u;
            dfs(x);
        }
    }
}
#define task "PRODUCE24"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    g.resize(n + 1);
    w.resize(n + 1);
    vs.resize(n + 1, false);
    par.resize(n + 1, -1);
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    long long rmax = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            // cerr << i << ' ' << j << endl;
            fill(vs.begin(), vs.end(), false);
            fill(par.begin(), par.end(), -1);
            dfs(i);
            if (!vs[j]) continue;
            long long v = j;
            vector <long long> ans;
            while (i != v && v != -1){
                ans.push_back(v);
                v = par[v];
            }
            ans.push_back(i);
            long long s = 0;
            if (ans.size() <= k + 1 && ans.size() > 0){
                long long s = 0;
                for (long long x : ans){
                    s += w[x];
                }
                rmax = max(rmax, s);
            }
        }
    }
    if (rmax == LLONG_MIN) rmax = 0;
    cout << rmax;
    return 0;
}