/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

void hoathang(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> ok(n + 1, 0);
    for (int i = 0, x; i < k; ++i){
        cin >> x;
        ok[x] = 1;
    }
    vector<vector<pair<int,int>>> g(n + 1);
    for (int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    while (q--){
        int X; int d;
        cin >> X >> d;
        if (ok[X]){
            cout << 0 << endl;
            continue;
        }
        //dijk
        vector<int> dis(n + 1, -1);
        queue<int> q;
        dis[X] = 0;
        q.push(X);
        int ans = -1;
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (auto &e : g[u]){
                int v = e.first;
                int c = e.second;
                if (c % d == 0 && dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    if (ok[v]){
                        ans = dis[v];
                        while (!q.empty()) q.pop();
                        break;
                    }
                    q.push(v);
                }
            }
        }
        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    while (t--){
        hoathang();
    }
    return 0;
}
