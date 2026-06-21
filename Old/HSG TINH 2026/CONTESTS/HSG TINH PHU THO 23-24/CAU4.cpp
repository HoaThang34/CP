/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU4"
int n;
vector<vector<int>> g;
vector<bool> vs;
int d = 0;
void bfs(long long u){
  vs[u] = true;
  queue<long long> q;
  q.push(u);
  while (!q.empty()){
    long long v = q.front();
    q.pop();
    d++;
    for (long long x : g[v]){
      if (!vs[x]){
        vs[x] = true;
        q.push(x);
      }
    }
  }
}
void hoathang(){
    cin >>n ;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    for (int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    cout << d/2 - 1<< endl;
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
