#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
void dfs(long long u){
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]){
      par[x] = u;
      dfs(x);
    }
  }
}
#define task "DFSOST2"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m >> s >> t;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  par.resize(n + 1, 0);
  
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  dfs(s);
  if (!vs[t]){
    cout << -1;
    return 0;
  }
  else{
    vector <long long> ans;
    while (s != t){
      ans.push_back(t);
      t = par[t];
    }
    ans.push_back(s);
    sort(ans.begin(), ans.end());
    for (long long x : ans) cout << x << ' ';
  }
  return 0;
}
