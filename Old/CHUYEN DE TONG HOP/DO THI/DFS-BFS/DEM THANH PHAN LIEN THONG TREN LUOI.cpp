#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long d = 0;
vector <vector <long long>> g;
long long dx[4] = {-1, 0, 0, 1};
long long dy[4] = {0, -1, 1, 0};
vector <pair<long long, long long>> s;
vector <vector<bool>> vs;

void dfs(long long i, long long j){
  vs[i][j] = true;
  for (int k = 0; k < 4; k++){
    long long i1 = i + dx[k];
    long long j1 = j + dy[k];
      if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !vs[i1][j1] && g[i1][j1] == 1){
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
    cin >> n >> m;
    g.resize(n + 1, vector <long long> (m + 1));
    vs.resize(n + 1, vector<bool> (m + 1, false));
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        cin >> g[i][j];
        // if (a[i][j] == 1){
        //   s.push_back({i, j});
        // }
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        if (!vs[i][j] && g[i][j] == 1){
          d++;
          dfs(i, j);
        }
      }
    }
    cout << d;
    return 0;
}