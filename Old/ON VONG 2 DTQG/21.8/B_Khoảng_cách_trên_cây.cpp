#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector<vector<pair<long long, long long>>> g;
void dfs(long long u, long long par, long long t, long long& ans, long long s){
    if(u == t){
        ans = s;
        return;
    }
    for(pair<long long, long long> x : g[u]){
        long long v = x.first;
        long long w = x.second;
        if(v != par){
            dfs(v, u, t, ans, s + w);
        }
    }
}
#define task "distance"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    cin >> n;
    g.resize(n + 1);
    for(int i = 0; i < n - 1; ++i){
        long long u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    cin >> q;
    while(q--){
        long long u, v;
        cin >> u >> v;
        long long ans = 0;
        dfs(u, 0, v, ans, 0);
        cout << ans << endl;
    }
    return 0;
}