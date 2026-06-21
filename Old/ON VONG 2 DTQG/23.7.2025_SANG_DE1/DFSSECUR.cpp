#include <bits/stdc++.h>
using namespace std;
long long n, m, s, k;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> ans;
void dfs(long long u){
  vs[u] = true;
  ans.push_back(u);
  for (long long x : g[u]){
    if (!vs[x]){
      dfs(x);
    }
  }
}
#define task "DFSSECUR"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> s >> k;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 1; i <= k; i++){
      long long x; cin >> x;
      if (s == x){
        cout << -1;
        return 0;
      }
      vs[x] = true;
    }
    for (int i = 1; i <= m; i++){
      long long u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(s);
    reverse(ans.begin(), ans.end());
    for (int i = ans.size() - 2; i >= 0; i--){
      for (int j = i; j < ans.size(); j++){
        cout << ans[j] <<' ';
      }
      cout << endl;
    }
    return 0;
}