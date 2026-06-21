#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> g;
vector <bool> vs;
void dfs(long long u){
  vs[u] = true;
  cout << u << ' ';
  for (long long x : g[u]){
    if (!vs[x]){
      dfs(x);
    }
  }
}
#define task "DFSNVLT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >>  m;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 1; i <= m; i++){
      long long u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    long long d = 0;
    // dfs(1);
    for (int i = 1; i <= n; i++){
      if (!vs[i]){
        d++;
        dfs(i);
        cout << endl;
      }
    }
    return 0;
}