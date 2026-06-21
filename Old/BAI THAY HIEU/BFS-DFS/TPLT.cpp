#include <bits/stdc++.h>
using namespace std;
#define task "sol"
long long n, m;
long long cnt = 0;
vector <vector <long long>> g;
vector <bool> vs;
void dfs(long long u){
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]){
      dfs(x);
    }
  }
}
void bfs(long long u){
  vs[u] = true;
  queue <long long> q;
  q.push(u);
  while (!q.empty()){
    long long k = q.front();
    q.pop();
    for (long long x : g[k]){
      if (!vs[x]){
        vs[x] = true;
        q.push(x);
      }
    }
  }
}
signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie();
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++){
    if (!vs[i]){
      cnt++;
      // dfs(i);
      bfs(i);
    }
  }
  cout << cnt;
  return 0;
}