/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "PROPATH"
int n;
vector<int> a;
vector <vector<int>> g;
vector <bool> vs;
int bfs(int s, int t){
    vector <int> d(n + 5, 0);
    queue<int> q;
    q.push(s);
    vs[s] = true;
    d[s] = 0;
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (u == t){
            return d[t];
        }
        for (int v : g[u]){
            if (!vs[v]){
                vs[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    g.resize(n + 5);
    vs.resize(n + 5, false);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            vs.assign(n + 5, false);
            int len = bfs(i, j);
            int rmin = min(a[i], a[j]);
            long long s = len*rmin;
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
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
