#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x;
vector <vector <pair<long long, long long>>> g1;
vector <long long> dijkstra(long long s, vector<vector<pair <long long, long long>>>& g){
    vector <long long> d(n + 1, LLONG_MAX);
    d[s] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    q.push({0, s});
    while (!q.empty()){
        pair<long long, long long> top = q.top(); q.pop();
        long long u = top.second;
        long long kc = top.first;
        if (kc > d[u]){
        continue;
        }
        for (auto x : g[u]){
        long long v = x.second;
        long long w = x.first;
        if (d[v] > d[u] + w){
            d[v] = d[u] + w;
            q.push({d[v], v});
        }
        }
    }
    return d;
    // cout << d[n];
}
void subtask2(){ // k==n;
    vector <long long> d = dijkstra(1, g1);
    // cout << d[n];
    long long ans = d[n];
    if (ans > x){
        cout << -1;
        return;
    }
    else{
        cout << ans;
        return;
    }
}
vector <vector <pair <long long, long long>>> g2;
void subtask1(){
    vector<long long> d1 = dijkstra(1, g2);
    vector<long long> dN = dijkstra(n, g2);
    vector<long long> dK = dijkstra(1, g1);
    long long ans = LLONG_MAX;
    for(int u=1;u<=n;u++){
        for(auto e: g2[u]){
            long long v = e.second;
            long long a = e.first;
            if(dK[u] + a <= x && d1[u]<LLONG_MAX && dN[v]<LLONG_MAX){
                ans = min(ans, d1[u] + a + dN[v]);
            }
        }
    }
    if(ans==LLONG_MAX) cout << -1;
    else cout << ans;
}

#define task "road"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> k >> x;
    g1.resize(n + 1);
    g2.resize(n + 1);
    for (int i = 1; i <= m; i++){
        long long u, v, a, b;
        cin >> u >> v >> a >> b;
        g1[u].push_back({b, v});
        g2[u].push_back({a, v});
    }
    // subtask2();
    if (k == n){
        subtask2();
    }
    else{
        subtask1();
    }
    return 0;
}
