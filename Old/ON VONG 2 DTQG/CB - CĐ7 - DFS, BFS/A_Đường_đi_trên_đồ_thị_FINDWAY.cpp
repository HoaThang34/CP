#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
void dfs(long long u){
    vs[u] = true;
    for (long long v : g[u]){
        if (!vs[v]){
            par[v] = u;
            dfs(v);
        }
    }
}
#define task "FINDWAY"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> s >> t;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    par.resize(n + 1, 0);
    for (int i = 1; i <= m; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s);
    if (!vs[t]){
        cout << -1;
        return 0;
    }
    vector <long long> ans;
    while (s != t){
        ans.push_back(t);
        t = par[t];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (long long x : ans){
        cout << x << ' ';
    }
    return 0;
}