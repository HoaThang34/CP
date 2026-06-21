#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long m, n, k;
vector<vector<bool>> vs;
vector<vector<long long>> g;
long long dfs(long long i, long long j){
    if(i < 1 || j < 1 || vs[i][j]){
        return 0;
    }
    if(i == 1 && j == 1){
        return 1;
    }
    if(g[i][j] != -1){
        return g[i][j];
    }
    long long d = dfs(i - 1, j);
    long long u = dfs(i, j - 1);
    long long dis = (d + u) % MOD;
    return g[i][j] = dis;
}
void subtask1(){
    cout << dfs(m, n) << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n >> k;
    vs.resize(m + 1, vector<bool>(n + 1, false));
    g.resize(m + 1, vector<long long>(n + 1, -1));
    for(int i = 0; i < k; ++i){
        long long r, c;
        cin >> r >> c;
        vs[r][c] = true;
    }
    subtask1();
    return 0;
}