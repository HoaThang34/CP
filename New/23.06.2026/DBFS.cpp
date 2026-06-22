/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "DBFS"
#define endl '\n'
#define int long long
int n, m, s;
vector<vector<int>> g;
map<int, int> cnt1, cnt2, cnt3, cnt4;
vector<bool> vs;
int t = 0;
void dfs(int u){
    vs[u] = true;
    t++;
    cnt1[u] = t;
    for (int x : g[u]){
        if (!vs[x]){
            dfs(x);
        }
    }
    t++;
    cnt2[u]=t;
}
void bfs(int u){
    vs[u] = true;
    queue<int> q;
    t++;
    cnt3[u] = t;
    q.push(u);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        t++;
        cnt4[v] = t;
        for (int x : g[v]){
            if (!vs[x]){
                vs[x] = true;
                t++;
                cnt3[x] = t;
                q.push(x);
            }
        }
    }
}
void hoathang(){
    cin >> n >> m >> s;
    g.resize(n + 5);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vs.assign(n + 5, false);
    dfs(s);
    t = 0;
    vs.assign(n + 5, false);
    bfs(s);
    for (int i = 1; i <= n; i++){
        cout << cnt1[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << cnt2[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << cnt3[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        cout << cnt4[i] << ' ';
    }
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
