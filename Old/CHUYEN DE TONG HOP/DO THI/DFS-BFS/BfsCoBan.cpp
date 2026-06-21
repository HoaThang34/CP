#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
vector <vector<long long>> g;
vector <bool> vs;
void bfs(long long u){
  vs[u] = true;
  queue<long long> q;
  q.push(u);
  while (!q.empty()){
    long long v = q.front();
    q.pop();
    cout << v << ' ';
    for (long long x : g[v]){
      if (!vs[x]){
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
    cin >> n >> m >> s;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 1; i <= m; i++){
      long long u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    bfs(s);
    return 0;
}