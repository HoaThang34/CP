#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector <vector <long long>> g;
vector <long long> dist;
#define task "EVA"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    g.resize(n + 1);
    dist.resize(n + 1, -1);
    queue<long long> q;
    for (int i = 0; i < k; i++){
        long long x;
        cin >> x;
        q.push(x);
        dist[x] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        for (long long v : g[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (long long i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}