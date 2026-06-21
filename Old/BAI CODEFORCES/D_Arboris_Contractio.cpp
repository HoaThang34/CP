#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t; 
    if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> d(n+1,0);
        for(int i=0;i<n-1;i++){
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u]++; d[v]++;
        }
        if(n<=3){ cout << 0 << '\n'; continue; }
        int c1=0;
        for(int i=1;i<=n;i++) if(d[i]==1) c1++;
        int mx=0;
        for(int u=1;u<=n;u++){
            int c=0;
            for(int v: g[u]) if(d[v]==1) c++;
            if(c>mx) mx=c;
        }
        cout << c1 - mx << '\n';
    }
    return 0;
}
