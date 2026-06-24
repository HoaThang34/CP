/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "SHORTEST"
#define endl '\n'
#define int long long
int n, m;
vector<vector<pair<int,int>>> g;
vector<bool> vs;
int dijkstra(int s){
    vector<int> d1(n + 1, LLONG_MAX), d2(n+1, LLONG_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    d1[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        pair<int,int> top = q.top(); q.pop();
        int u = top.second;
        int kc = top.first;
        // if (vs[u]) continue;
        // vs[u] = true;
        if (kc > d2[u]){
            continue;
        }
        for (pair<int,int> p : g[u]){
            int v = p.first;
            int w = p.second;
            if (d1[v] > kc + w){
                d2[v] = d1[v];
                d1[v] = kc + w;
                q.push({kc + w, v});
            }
            else if (kc + w < d2[v] && kc + w > d1[v]){
                d2[v] = kc + w;
                q.push({kc + w, v});
            }
        }
    }
    if (d2[n] == LLONG_MAX) return -1;
    return d2[n];
}
void hoathang(){
    cin >> n >> m;
    g.resize(n + 5);
    vs.resize(n + 5, 0);
    for (int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    cout << dijkstra(1) << endl;
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
