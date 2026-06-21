#include <bits/stdc++.h>
using namespace std;
long long n, k, m;
vector <long long> out;
vector <vector<long long>> g;
vector <long long> vs;
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
long long xuli(long long s, vector <long long> k){
  fill(vs.begin(), vs.end(), false);
  par.assign(n + 1, -1);
  dfs(s);
  long long rmin = LLONG_MAX;
  for (long long t : k){
    if (!vs[t]) continue;
    vector <long long> ans;
    while (s != t){
      ans.push_back(t);
      t = par[t];
    }
    ans.push_back(s);
    rmin = min(rmin, (long long)ans.size() - 1);
  }
  return rmin;
}

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    out.resize(n + 1);
    for (int i = 1; i <= k; i++){
      cin >> out[i];
    }
    cin >> m;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 1; i <= m; i++){
      long long u, v;
      cin >> u >> v;
      g[v].push_back(u);
      g[u].push_back(v);
    }
    vector <long long> d (n + 1, LLONG_MAX);
    queue<long long> q;
    for (long long x : out){
      d[x] = 0;
      q.push(x);
    }
    while (!q.empty()){
      long long k = q.front(); q.pop();
      for (long long x : g[k]){
        if (d[x] > d[k] + 1){
          d[x] = d[k] + 1;
          q.push(x);
        }
      }
    }
    for (int i = 1; i <= n; i++){
      cout << d[i] << ' ';
    }
    return 0;
}