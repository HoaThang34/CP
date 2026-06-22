/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "MONEY"
#define endl '\n'
#define int long long
int n, m, k, a, b;
vector <vector<pair<int,int>>> g;
vector <pair<int,int>> W;
vector <bool> vs;
const int N = 2e18;
vector<int> dijkstra(int s){
    vector <int> d(n + 5, N);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    while(!q.empty()){
        pair<int, int> top = q.top(); q.pop();
        int u = top.second;
        int kc = top.first;
        if(vs[u]) continue;
        vs[u] = true;
        for (pair<int, int> it : g[u]){
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    return d;
}
void hoathang(){
    cin >> n >> m >> k >> a >> b;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    for (int i = 1; i <= k; i++){
        int s, w;
        cin >> s >> w;
        W.push_back({s, w});
    }
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vs.assign(n + 5, false);
    vector<int> d1 = dijkstra(a);
    vs.assign(n + 5, false);
    vector<int> d2 = dijkstra(b);
    int ans = N;
    for (pair<int, int> it : W){
        int s = it.first, w =it.second;
        ans = min(ans, d1[s] + d2[s] + w);
    }
    cout << ans << endl;
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
