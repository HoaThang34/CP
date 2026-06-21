#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> g;
vector <long long> w;
vector <long long> par;
vector <bool> vs;
long long rmax = 0, ans = 0;
void dfs(long long u){
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]){
      par[x] = u;
      dfs(x);
    }
  }
}
#define task "KHOBAU"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m;
  g.resize(n + 1);
  w.resize(n + 1);
  vs.resize(n + 1, false);
  par.resize(n + 1, 0);
  for (int i = 1; i <= n; i++){
    cin >> w[i];
  }
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++){
    fill(vs.begin(),vs.end(),false);
    par[i] = i;
    dfs(i);
    for (int j = 1; j <= n; j++){
      if (i != j && vs[j]){
        rmax = 0;
        long long k = j;
        while (k != i){
          rmax += w[k];
          k = par[k];
        }
        rmax += w[i];
        ans = max(ans, rmax);
      }
    }
  }
  cout << ans;
  return 0;
}

