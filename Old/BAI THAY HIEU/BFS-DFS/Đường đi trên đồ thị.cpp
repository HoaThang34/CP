#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
void dfs(long long u){
  vs[u] = true;
  for (long long v : g[u]){
    if (!vs[v]){
      par[v] = u;
      dfs(v);
    }
  }
}
void bfs(long long u){
  vs[u] = true;
  queue <long long> q;
  q.push(u);
  while (!q.empty()){
    long long k = q.front();
    q.pop();
    for (long long x : g[k]){
      if (!vs[x]){
        par[x] = k;
        vs[x] = true;
        q.push(x);
      }
    }
  }
}
#define task "sol"
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
      g[v].push_back(u);
    }
    // dfs(s);
    bfs(s);
    if (!vs[t]){
      cout << - 1;
    }
    else{
      vector <long long> res;
      while (t != s){
        res.push_back(t);
        t = par[t];
      }
      res.push_back(s);
      reverse(res.begin(), res.end());
      cout << res.size() << endl;
      for (long long x : res){
        cout << x << ' ';
      }
    }
    return 0;
}