#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t;
vector <vector <pair<long long, long long>>> g;
void dijkstra(long long s, long long t){
  vector <long long> d (n + 1, LLONG_MAX);
  priority_queue<pair<long long, long long>, vector <pair<long long, long long>>, greater<pair<long long, long long>>> q;
  d[s] = 0;
  q.push({0, s});
  while (!q.empty()){
    pair <long long, long long> top = q.top(); q.pop();
    long long u = top.second;
    long long kc = top.first;
    if (kc > d[u]) continue;
    for (auto x : g[u]){
      long long v = x.second;
      long long w = x.first;
      if (d[v] > d[u] + w){
        d[v] = d[u] + w;
        q.push({d[v], v});
      }
    }
  }
  cout << d[t];
}
#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m >> s >> t;
  g.resize(n + 1);
  for (int i = 1; i <= m; i++){
    long long u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
  }
  dijkstra(s, t);
  return 0;
}

