#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> g;
vector <bool> vs;
vector <pair<long long, long long>> c;

void dfs(long long u){
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]) dfs(x);
  }
}
void dfs2(long long u, long long s, long long t){
  vs[u] = true;
  for (long long v : g[u]){
    if ((u == s && v == t) || (u == t && v == s)) continue;
    if (!vs[v]) dfs2(v, s, t);
  }
}
#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n  >> m ;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v ;
    g[u].push_back(v);
    g[v].push_back(u);
    c.push_back({u, v});
  }
  long long d1 = 0, d2 = 0, ans1 = 0;
  for (int i = 1; i <= n; i++){
    if (!vs[i]){
      d1++;
      dfs(i);
    }
  }
  for (int i = 1; i <= n; i++){
    fill(vs.begin(), vs.end(), false);
    vs[i] = true;
    d2 = 0;
    for (int j = 1; j <= n; j++){
      if (!vs[j]){
        d2++;
        dfs(j);
      }
    }
    if (d2 > d1){
      ans1++;
    }
  }
  cout << ans1 << ' ';
  long long d3 = 0, ans2 = 0;
  for (auto x : c){
      vs.assign(n + 1, false);
      d3 = 0;
      for (int j = 1; j <= n; j++){
        if (!vs[j]){
          d3++;
          dfs2(j, x.first, x.second);
        }
      }
      if (d3 > d1) ans2++;
  }
  cout << ans2;
  return 0;
}
