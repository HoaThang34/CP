#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
vector <vector<long long>> g;
vector <bool> vs;
vector <long long> ans;
void dfs(long long u){
  vs[u] = true;
  ans.push_back(u);
  for (long long v : g[u]){
    if (!vs[v]){
      dfs(v);
    }
  }
}
#define task "DFSLVLT"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >>n >> m >> s;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(s);
  if (ans.size() == 1){
    cout << -1;
    return 0;
    
  }
  vector <long long> ans1;
  for (int i = 1; i < ans.size(); i++){
    ans1.push_back(ans[i]);
  }
  sort(ans1.begin(), ans1.end());
  for (long long x : ans1) cout << x << ' ';
  return 0;
}
