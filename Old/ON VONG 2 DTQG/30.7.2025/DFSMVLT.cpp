#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> ans;
vector <long long> ans1;
void dfs(long long u){
  vs[u] = true;
  ans1.push_back(u);
  for (long long v : g[u]){
    if (!vs[v]){
      dfs(v);
    }
  }
}
#define task "DFSMVLT"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >>n >> m;
  g.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  // long long d = 0;
  for (int i = 1; i <= n; i++){
    if (!vs[i]){
      ans1.clear();
      dfs(i);
      if (ans.size() < ans1.size()){
        ans = ans1;
      }
      // d++;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (long long x : ans){
    cout << x << ' ';
  }
  // cout << d;
  return 0;
}
