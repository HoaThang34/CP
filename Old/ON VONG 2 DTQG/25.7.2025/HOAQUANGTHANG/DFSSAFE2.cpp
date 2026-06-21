#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
vector <vector <long long>> g;
vector <bool> vs;
long long d;
void dfs(long long u, long long v){
  if (u == v){
    d++;
    return;
  }
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]){
      dfs(x, v);
      if (d >= 2) return;
    }
  }
}
#define task "DFSSAFE2"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m >> s;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  bool check = false;
  for (int i = 1; i <= n; i++){
    d = 0;
    dfs(s, i);
    vs.assign(n + 1, false); 
    if (d >= 2){
      cout << i << ' ';
      check = true;
    }
  }
  if (check == false) cout << 0;
  return 0;
}
