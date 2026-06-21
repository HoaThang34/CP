#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <vector <long long>> g, g1;
vector <bool> vs;
stack<long long> st;
long long d = 0;
void dfs1(long long u){
  vs[u] = true;
  for (long long x : g[u]){
    if (!vs[x]){
      dfs1(x);
    }
  }
  st.push(u);
}

void dfs2(long long u){
  vs[u] = true;
  for (long long x : g1[u]){
    if (!vs[x]){
      dfs2(x);
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
  cin >> n >> m;
  g. resize(n + 1);
  g1.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= m; i++){
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g1[v].push_back(u);
    
  }
  fill(vs.begin(), vs.end(), false);
  for (int i = 1; i <= n; i++){
    if(!vs[i]){
      dfs1(i);
    }
  }
  fill(vs.begin(), vs.end(), false);
  while (!st.empty()){
    long long k = st.top(); st.pop();
    if (!vs[k]){
      dfs2(k);
      d++;
    }
  }
  if (d == 1) cout << "YES";
  else cout << "NO";
  return 0;
}
