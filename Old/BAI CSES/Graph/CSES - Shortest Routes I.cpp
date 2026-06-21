#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector<pair<long long, long long>>> g;
vector <bool> vs;
void dijkstra(long long s){
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
  for (int i = 1; i <= n; i++){
    cout << d[i] << ' ';
  }
}
#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({w, v});
    // g[v].push_back({u, w});
    
  }
  dijkstra(1);
  return 0;
}
