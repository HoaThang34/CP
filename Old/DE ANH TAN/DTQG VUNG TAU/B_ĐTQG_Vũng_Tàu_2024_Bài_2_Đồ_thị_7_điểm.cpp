#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<pair<long long, long long>>> g;
#define task "GRAPH"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    vector<long long> d(n + 1, LLONG_MAX);
    deque<long long> dq;
    d[1] = 0;
    dq.push_front(1);
    while(!dq.empty()){
        long long u = dq.front();
        dq.pop_front();
        for(auto x : g[u]){
            long long v = x.first;
            long long w = x.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                if(w == 0){
                    dq.push_front(v);
                }
                else {
                    dq.push_back(v);
                }
            }
        }
    }
    if(d[n] == LLONG_MAX){
        cout << -1;
    }
    else {
        cout << d[n];
    }
    return 0;
}