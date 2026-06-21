/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "REPAINT"
#define int long long
const int INF = 1e18;
int n, m;
vector<vector<int>> adj;
vector<int> c;
vector<int> d;
vector<int> vs;
vector<int> color;
void bfs(int s, vector<int>& a, bool& ok){
    queue<int> q;
    ok = true;
    q.push(s);
    vs[s] = 1;
    color[s] = 1;
    a.push_back(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (vs[v] == 0) {
                vs[v] = 1;
                color[v] = 3 - color[u];
                q.push(v);
                a.push_back(v);
            }
            else if (color[v] == color[u]) {
                ok = false;
            }
        }
    }
}

void hoathang(){
    cin >> n >> m;
    adj.resize(n + 1);
    c.resize(n + 1);
    d.resize(n + 1);
    vs.assign(n + 1, 0);
    color.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vs[i] == 0) {
            vector<int> a;
            bool ok;
            bfs(i, a, ok);
            if (!ok) {
                cout << -1 << endl;
                return;
            }
            int dis1 = 0;
            int dis2 = 0;
            for (int v : a) {
                if (c[v] != color[v]) {
                    if (d[v] == 0) {
                        dis1 = INF;
                    }
                    else{
                        dis1++;
                    }
                }
                if (c[v] != (3 - color[v])) {
                     if (d[v] == 0) {
                        dis2 = INF;
                    }
                    else {
                        dis2++;
                    }
                }
            }
            int rmin = min(dis1, dis2);
            if (rmin >= INF) {
                cout << -1 << endl;
                return;
            }
            ans += rmin;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".INP", "r")){
        freopen(nap".INP", "r", stdin);
        freopen(nap".OUT", "w", stdout);
    }
    hoathang();
    return 0;
}