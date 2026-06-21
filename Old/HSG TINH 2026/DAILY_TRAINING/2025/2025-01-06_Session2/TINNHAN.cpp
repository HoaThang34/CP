/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "TINNHAN"
int n, m;
vector<vector<int>> g;
vector <bool> vs;
void dfs(int u){
    vs[u] = true;
    for (int v : g[u]){
        if (!vs[v]) dfs(v);
    }
}
void hoathang(){
    cin >> n >> m;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int d = 0;
    for (int i = 1; i <= n; i++){
        if (!vs[i]){
            dfs(i);
            d++;
        }
    }
    cout << d << endl;
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
