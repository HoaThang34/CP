#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define task "sol"
const ll mod=1000000007;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int n,m,p;
    cin>>n>>m>>p;
    vector<int>a(p+2);
    a[0]=1;
    for(int i=1;i<=p;i++) cin>>a[i];
    a[p+1]=n;
    vector<vector<int>>e(n+1);
    vector<int>deg(n+1);
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        e[u].push_back(v);
        deg[v]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
    vector<int>topo;
    topo.reserve(n);
    while(!q.empty()){
        int u=q.front(); q.pop();
        topo.push_back(u);
        for(int v:e[u]) if(--deg[v]==0) q.push(v);
    }
    vector<int>idx(n+1);
    for(int i=0;i<n;i++) idx[topo[i]]=i;
    vector<ll>dp(n+1);
    ll res=1;
    for(int i=0;i+1<(int)a.size();i++){
        int u=a[i], v=a[i+1];
        int l=idx[u], r=idx[v];
        for(int j=l;j<=r;j++) dp[topo[j]]=0;
        dp[u]=1;
        for(int j=l;j<=r;j++){
            int x=topo[j];
            if(dp[x]){
                for(int y:e[x]){
                    if(idx[y]<=r){
                        dp[y]=(dp[y]+dp[x])%mod;
                    }
                }
            }
        }
        res=res*dp[v]%mod;
        if(res==0) break;
    }
    cout<<res<<"\n";
    return 0;
}
