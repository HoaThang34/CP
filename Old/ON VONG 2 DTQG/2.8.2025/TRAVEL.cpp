#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, long long>>> g;
vector<long long> c1, c2;
vector<long long> d;
long long n;
bool dfs(long long u, long long t, long long par){
    if(u == t){
        return true;
    }
    // cerr << u << ' ';
    for(int i = 0; i < g[u].size(); i++){
        long long v = g[u][i].first;
        long long w = g[u][i].second;
        if(v != par){
            if(dfs(v, t, u)){
                d[w]++;
                return true;
            }
        }
    }
    return false;
}
#define task "TRAVEL"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    g.resize(n + 1);
    c1.resize(n);
    c2.resize(n);
    d.resize(n);
    for(int i = 1; i < n; i++){
        long long u, v;
        cin >> u >> v >> c1[i] >> c2[i];
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    for(int i = 1; i < n; i++){
        dfs(i, i + 1, -1);
    }
    long long ans = 0;
    for(int i = 1; i < n; i++){
        if(d[i] > 0){
            long long res = d[i] * c1[i];
            ans += min(res, c2[i]);
        }
    }
    cout << ans << endl;
    return 0;
}