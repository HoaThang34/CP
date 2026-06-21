#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
vector <long long> ans;
void dfs(long long u){
  vs[u] = true;
  ans.push_back(u);
  for (long long x : g[u]){
    if (!vs[x]){
      dfs(x);
      par[x] = u;
    }
  }
}
#define task "DFSORIEN"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> s;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    par.resize(n + 1, 0);
    for (int i = 1; i <= m; i++){
      long long u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(s);
    for (long long x : ans){
      if (x == s){
        continue;
      }
      else{
        vector <long long> ans1;
        while (x != s){
          ans1.push_back(x);
          x = par[x];
        }
        ans1.push_back(s);
        for (long long k : ans1){
          cout << k << ' ';
        }
        cout << endl;
      }
    }
    return 0;
}