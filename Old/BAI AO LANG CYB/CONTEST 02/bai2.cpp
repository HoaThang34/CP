/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n, m;
vector <vector <long long>> g;
vector <bool> vs;
vector <long long> par;
long long st, en;
bool dfs(long long u){
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]){
      par[x] = u;
      if (dfs(x)) return true;
    }
    else if (x != par[u]){
      st = x; en = u;
      return true;
    }
  }
  return false;
}
void hoathang(){
    cin >> n >> m;
    g.resize(n + 1);
    vs.resize(n + 1, false);
    par.resize(n + 1, 0);
    for (int i = 1; i <= m; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!vs[i] && dfs(i)){
          vector <long long> ans;
          ans.push_back(st);
          while (st  != en){
            ans.push_back(en);
            en = par[en];
          }
          ans.push_back(st);
          reverse(ans.begin(), ans.end());
          cout << ans.size() << endl;
          for (long long x : ans){
            cout << x << ' ';
          }
          return;
        }
    }
    cout << "IMPOSSIBLE";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
