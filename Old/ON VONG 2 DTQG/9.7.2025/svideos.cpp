#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <pair<long long, long long>> adj;
vector <long long> visit;

#define task "svideos"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        long long u, v, k;
        cin >> u >> v >> k;
        adj[u].push_back({v, k});
        adj[v].push_back({u, k});

    }
    while (q--){
        long long a, b;
        cin >> a >> b;
        long long d = 0;
        
    }
    return 0;
}