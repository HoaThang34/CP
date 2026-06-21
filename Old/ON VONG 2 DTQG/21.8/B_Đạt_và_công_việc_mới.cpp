#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
vector<long long> w;
vector<pair<long long, long long>> adj;
vector<bool> vs;
void dfs(long long u, vector<bool>& vis, vector<vector<long long>>& g, long long& s){
    vis[u] = true;
    s += w[u];
    for(long long v : g[u]){
        if(!vis[v]){
            dfs(v, vis, g, s);
        }
    }
}
void subtask1(){
    vs.resize(m + 1, false);
    for(int k = 0; k < q; k++){
        char loai;
        cin >> loai;
        if(loai == 'C'){
            long long i, val;
            cin >> i >> val;
            w[i] = val;
        }
        else{
            long long j;
            cin >> j;
            vs[j] = true;
        }
        vector<vector<long long>> g(n + 1);
        for(long long i = 1; i <= m; i++){
            if(!vs[i]){
                long long u = adj[i].first;
                long long v = adj[i].second;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        long long rmax = LLONG_MIN;
        vector<bool> vis(n + 1, false);
        for(long long i = 1; i <= n; i++){
            if(!vis[i]){
                long long s = 0;
                dfs(i, vis, g, s);
                rmax = max(rmax, s);
            }
        }
        cout << rmax << endl;
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> q;
    w.resize(n + 1);
    adj.resize(m + 1);
    for(long long i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(long long i = 1; i <= m; i++){
        cin >> adj[i].first >> adj[i].second;
    }
    subtask1();
    return 0;
}