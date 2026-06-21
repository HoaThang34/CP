/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define nap "1671"
#define endl '\n'
#define int long long
const long long N = 2e18;
int n, m;
vector <vector<pair<int, int>>> g;
void dijkstra(int s){
    vector<int> d(n + 5, N);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()){
        pair<int,int> top = q.top();
        q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u]) continue;
        for (pair<int, int> it : g[u]){
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << d[i] << ' ';
    }
}
void hoathang(){
//    cout << "hoathang" << endl;
    cin >> n >> m;
    g.resize(n + 5);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra(1);
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
