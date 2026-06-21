#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
long long n, m;
vector<long long> dijkstra(long long n, long long s, vector<vector<pair<long long,long long>>> &g){
    vector<long long> d(n+1, N);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        long long du = pq.top().first;
        long long u = pq.top().second;
        pq.pop();
        if(du != d[u]) continue;
        for(auto e : g[u]){
            long long v = e.first, w = e.second;
            if(d[v] > du + w){
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    vector<vector<pair<long long,long long>>> g(n+1), rg(n+1);
    for(long long i=1;i<=m;i++){
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
    }
    vector<long long> d1 = dijkstra(n, 1, g);
    for(long long i=1;i<=n;i++){
        if(d1[i] < N) rg[1].push_back({i, d1[i]});
    }
    vector<long long> d2 = dijkstra(n, 1, rg);
    for(long long i=2;i<=n;i++){
        if(d2[i] < N) cout << d2[i] << ' ';
        else cout << -1 << ' ';
    }
    return 0;
}