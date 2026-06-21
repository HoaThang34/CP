#include <bits/stdc++.h>
using namespace std;
#define task "sol"
const int MAXN = 70005;
const int LOG = 17;
int n,q;
vector<int> g[MAXN];
int up[LOG+1][MAXN];
int d[MAXN];
int st[4*MAXN];
int Nn;
void dfs(int u,int p){
    up[0][u]=p;
    for(int k=1;k<=LOG;k++) up[k][u]= up[k-1][u]? up[k-1][ up[k-1][u] ]:0;
    for(int v:g[u]) if(v!=p){
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
int lca(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    if(d[a]<d[b]) swap(a,b);
    int diff=d[a]-d[b];
    for(int k=0;k<=LOG;k++) if(diff&(1<<k)) a=up[k][a];
    if(a==b) return a;
    for(int k=LOG;k>=0;k--) if(up[k][a]!=up[k][b]){
        a=up[k][a];
        b=up[k][b];
    }
    return up[0][a];
}
int comb(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    return lca(a,b);
}
void build(int v,int l,int r){
    if(l==r) st[v]=l;
    else{
        int m=(l+r)/2;
        build(v*2,l,m);
        build(v*2+1,m+1,r);
        st[v]=comb(st[v*2],st[v*2+1]);
    }
}
int query(int v,int l,int r,int L,int R){
    if(R<l||r<L) return 0;
    if(L<=l&&r<=R) return st[v];
    int m=(l+r)/2;
    int a=query(v*2,l,m,L,R);
    int b=query(v*2+1,m+1,r,L,R);
    return comb(a,b);
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d[1]=0;
    dfs(1,0);
    Nn=n;
    build(1,1,Nn);
    for(int i=0;i<q;i++){
        int L,R;cin>>L>>R;
        cout<<query(1,1,Nn,L,R)<<"\n";
    }
    return 0;
}
