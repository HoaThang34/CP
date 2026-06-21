#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[1005], b[1005], tw;
vector<long long> adj[1005], ch[1005];
long long P[1005];
void dfs1(long long u,long long p){
    P[u]=p;
    for(long long v:adj[u]) if(v!=p){
        ch[u].push_back(v);
        dfs1(v,u);
    }
}
void dfs2(long long an,long long u){
    long long wa = max(a[an], a[u]);
    long long wb = max(b[an], b[u]);
    tw += min(wa, wb);
    for(long long v:ch[u]) dfs2(an,v);
}
#define task "MINMAX"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    for(long long i = 1; i <= n; i++) cin >> a[i];
    for(long long i = 1; i <= n; i++) cin >> b[i];
    for(long long i = 1; i < n; i++){
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    tw=0;
    for(long long u = 1; u <= n; u++){
        for(long long v:ch[u]) dfs2(u,v);
    }
    cout << tw;
    return 0;
}
