/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DICHUYEN"
int n, m, k, q;

vector<vector<pair<int, int>> g;
vector<bool> vs;
vector<long long> d;
void dijkstra(long long s){
    d.assign(n + 5, 1e18);
    priority_queue<pair<long long, long long>, vector<long long, long long>, greater <pair <long long, long long>>> pq;
    pq.push({0, s});
    while (!pq.empty()){
        pair <long long, long long> top = pq.top();
        pq.pop();
        long long dis = top.first;
        long long u = top.second();
        if (dis > d[u]){
            continue;
        }
        for (pair<long long, long long> p : g[u]){
            int v = p.second;
            int kc = p.first;
            if (d[v] > d[u] + kc){
                pq.push({d[v], v});
            }
        }
    }
}
void hoathang(){
    cin >> n>> m;
    g.resize(n + 5);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u>> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vs.resize(n + 5);
    cin >> k >> q;
    
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
