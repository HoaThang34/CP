#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
long long n, k;
vector <vector<pair<long long, long long>>> g;
vector<long long> bfs(long long s){
    vector<long long> d(n + 1, INF);
    d[s] = 0;
    queue<long long> q;
    q.push(s);
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        for(auto& x : g[u]){
            long long v = x.second;
            long long w = x.first;
            if(d[v] == INF){
                d[v] = d[u] + w;
                q.push(v);
            }
        }
    }
    return d;
}
void subtask1(){
    long long ans = 1e18;
    for (int i = 1; i <= n; i++){
        long long rmax = 0;
        vector<long long> d = bfs(i);
        for (int j = 1; j <= n; j++){
            rmax = max(rmax, d[j]);
        }
        ans = min(ans, rmax);
    }
    cout << ans;
}
#define task "KTREE" 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    g.resize(n + 1);
    for (int i = 1; i < n; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    subtask1();
    return 0;
}