#include <bits/stdc++.h>
using namespace std;
long long m, n;
vector <vector<char>> g;
vector <vector<bool>> vs;
vector<vector<pair<long long, long long>>> par;
long long x, y;
long long dx[4] = {-1, 0, 0, 1};
long long dy[4] = {0, -1, 1, 0};
void dfs(long long i, long long j){
  vs[i][j] = true;
  for (int k = 0; k < 4; k++){
    long long i1 = i + dx[k];
    long long j1 = j + dy[k];
    if (i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && !vs[i1][j1] && g[i1][j1] == '.'){
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
    g.resize(m + 1, vector <char> (n + 1));
    vs.resize(m + 1, vector <bool> (n + 1, false));
    par.resize(m + 1, vector<pair<long long, long long>>(n + 1, {-1, -1}));
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= n; j++){
        cin >> g[i][j];
        if (g[i][j] == 'E'){
          x = i;
          y = j;
        }
      }
    }
    dfs(x, y);
    pair<long long, long long> end1 = {-1, -1};
    for (int i = 1; i <= m; i++) {
        if (vs[i][1]) end1 = {i, 1};
        if (vs[i][n]) end1 = {i, n};
    }
    for (int j = 1; j <= n; j++) {
        if (vs[1][j]) end1 = {1, j};
        if (vs[m][j]) end1 = {m, j};
    }

    if (end1.first == -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    vector <pair<long long, long long>> ans;
    pair <long long, long long> f = end1;
    while (f != make_pair(x, y)){
      ans.push_back(f);
      f = par[f.first][f.second];
    }
    ans.push_back({x, y});
    reverse(ans.begin(), ans.end());
    for (auto x : ans){
      cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}