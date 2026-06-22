/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "DIJKSTRA"
#define endl '\n'
#define int long long
int n, m, s, t;
vector <vector <pair<int, int>>> g;
const int N = 2e18;
vector <bool> vs;
void dijkstra(int s, int t){
    vector<int> d(n + 5, N);
    d[s] = 0;
    priority_queue<pair<int,int>, vector <pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0,s});
    while(!q.empty()){
        pair<int,int> top = q.top();
        q.pop();
        int u = top.second;
        int kc = top.first;
        if (vs[u]) continue;
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
    cout << d[t] << endl;
}
void hoathang(){
    cin >> n >> m >> s >> t;
    g.resize(n + 5);
    vs.resize(n + 5, 0);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra(s, t);
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
