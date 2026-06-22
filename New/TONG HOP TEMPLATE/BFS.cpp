/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "BFS"
#define endl '\n'
#define int long long
int n,m,s;
vector <vector<int>> g;
vector <bool> vs;
void bfs(int u){
    vs[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (int x : g[v]){
            if (!vs[x]){
                vs[x] = true;
                q.push(x);
            }
        }
    }
}
void hoathang(){
    cin >> n >> m >> s;
    g.resize(n + 5);
    vs.resize(n + 5, 0);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        sort(g[i].begin(), g[i].end());
    }
    bfs(s);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
