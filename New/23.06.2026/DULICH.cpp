/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "DULICH"
#define endl '\n'
#define int long long
int n, m, s, t;
vector<vector<pair<int,int>>> g;
vector<bool> vs;
vector<int> par;
void dijkstra(int s, int t){
    vector<int> d(n + 5, LLONG_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    d[s] = 0;
    while(!q.empty()){
        pair<int,int> top = q.top(); q.pop();
        int u = top.second;
        int kc = top.first;
        if (vs[u]) continue;
        vs[u] = true;
        for (pair<int,int> p : g[u]){
            int v = p.first;
            int w = p.second;
            if (d[v] > d[u] + w){
                par[v] = u;
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    cout << d[t] << endl;
}
void hoathang(){
    cin >> n >> m;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    par.resize(n + 5, 0);
    for (int i = 1; i <= m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    cin >> s >> t;
    dijkstra(s, t);
    int k = t;
    vector<int> ans;
    while(k != s){
        ans.push_back(k);
        k = par[k];
        // cerr << k << ' ';
    }
    // cerr << "hoathang" << endl;
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << ' ';
    for (int x : ans) cout << x << ' ';
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
