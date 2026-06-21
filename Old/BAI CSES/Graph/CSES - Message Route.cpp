#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
void bfs(long long u){
  vs[u] = true;
  queue<long long> q;
  q.push(u);
  while (!q.empty()){
    long long k = q.front(); q.pop();
    for (long long x : g[k]){
      if (!vs[x]){
        par[x] = k;
        q.push(x);
        vs[x] = true;
      }
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
  cin >> n >> m;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  par.resize(n + 1, 0);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(1);
  if (!vs[n]){
    cout << "IMPOSSIBLE";
  }
  else{
    vector <long long> ans;
    while (n != 1){
      ans.push_back(n);
      n = par[n];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (long long x : ans) cout << x << ' ';
  }
  return 0;
}
