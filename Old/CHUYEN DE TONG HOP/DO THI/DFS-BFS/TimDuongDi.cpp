#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t;
vector <vector<long long>> adj;
vector <bool> vs;
vector <long long> p;
void dfs(long long u){
    vs[u] = true;
    for (long long v : adj[u]){
        if (!vs[v]){
            p[v] = u;
            dfs(v);
        }
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> s >> t;
    adj.resize(n + 1);
    vs.resize(n + 1, false);
    p.resize(n + 1);
    for (int i = 1; i <= m; i++){
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(s);
    if (!vs[t]){
        cout << -1;
        return 0;
    }
    long long k = t;
    vector <long long> res;
    while (k != 0){
        res.push_back(k);
        k = p[k];
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (long long x : res){
        cout << x << ' ';
    }
    return 0;
}