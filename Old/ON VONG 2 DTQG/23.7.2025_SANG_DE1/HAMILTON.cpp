#include <bits/stdc++.h>
using namespace std;
long long n, m, d;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
bool dfs(long long u){
  if (d == n && find(g[u].begin(), g[u].end(), 1) != g[u].end()){
        return true;
      }
  for (long long x : g[u]){
    if (!vs[x]){
      vs[u] = true;
      d++;
      par[x] = u;
      if (dfs(x)) return true;
      vs[x] = false;
      d--;
    }
  }
  return false;
}
#define task "HAMILTON"
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
      long long u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    d = 1;
    if (dfs(1)) cout << "YES";
    else cout << "NO";
    return 0;
}