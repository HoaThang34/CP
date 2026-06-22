/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "School"
#define endl '\n'
#define int long long
int n, m, k;
vector<vector<pair<int, int>>> g1, g2, g3;
const int N = 2e18;
vector<int> dijkstra(int s, vector<vector<pair<int,int>>> &g){
    vector<bool> vs(n + 5, 0);
    vector<int> d(n + 5, N);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    d[s] = 0;
    q.push({0, s});
    while (!q.empty()){
        pair<int, int> top = q.top(); q.pop();
        int u = top.second;
        int kc = top.first;
        if (vs[u]) continue;
        vs[u] = true;
        for (pair<int,int> p : g[u]){
            int v = p.first;
            int w = p.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    return d;
}
void hoathang(){
    cin >> n >> m >> k;
    g1.resize(n + 5);
    g2.resize(n + 5);
    g3.resize(n + 5);
    for (int i1 = 1; i1 <= m; i1++){
        int i, j, a, b;
        cin >> i >> j >> a >> b;
        g1[i].push_back({j, b});
        g2[j].push_back({i, b});
        g3[j].push_back({i, a});
    }  
    int ans = N;
    vector<int> d1 = dijkstra(1, g1), d2 = dijkstra(n, g2), d3 = dijkstra(k, g3);
    for (int i = 1; i <= n; i++){
        if (d1[i] + d3[i] <= 60){
            ans = min(ans, d1[i] + d2[i]);
        }
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
