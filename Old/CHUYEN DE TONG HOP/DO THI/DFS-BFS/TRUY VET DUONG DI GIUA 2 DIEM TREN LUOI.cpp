#include <bits/stdc++.h>
using namespace std;
long long m, n;
vector <vector <long long>> g;
vector <vector <bool>> vs;
long long x1, x2, x3, x4;
vector <vector<pair<long long, long long>>> par;
long long dx[4] = {-1, 0, 0, 1};
long long dy[4] = {0, -1, 1, 0};
void dfs(long long i, long long j){
  vs[i][j] = true;
  for (int k = 0; k < 4; k++){
    long long i1 = i + dx[k];
    long long j1 = j + dy[k];
    if (i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && !vs[i1][j1] && g[i1][j1] == 0){
      par[i1][j1] = {i, j};
      dfs(i1, j1);
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
    cin >> m >> n;
    g.resize(m + 1, vector <long long> (n + 1));
    vs.resize(m + 1, vector <bool> (n + 1, false));
    par.resize(m + 1, vector <pair<long long, long long>> (n + 1, {0, 0}));
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= n; j++){
        cin >> g[i][j];
      }
    }
    cin >> x1 >> x2;
    cin >> x3 >> x4;
    dfs(x1, x2);
    if (!vs[x3][x4]){
      cout << "NO";
      return 0;
    }
    else{
      cout << "YES" << endl;
      pair <long long, long long> p = {x3, x4};
      vector <pair<long long, long long>> ans;
      while (p != make_pair(x1, x2)){
        ans.push_back(p);
        p = par[p.first][p.second];
      }
      ans.push_back({x1, x2});
      reverse(ans.begin(), ans.end());
      for (auto x : ans){
        cout << x.first << ' ' << x.second << endl;
      }
    }
    return 0;
}