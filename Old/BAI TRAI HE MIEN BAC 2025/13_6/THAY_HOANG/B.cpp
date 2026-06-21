#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define task "sol"
const ll INF = (ll)4e18;
const ll MOD = 1000000007;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int n,m,d;
    cin>>n>>m>>d;
    vector<vector<pair<int,ll>>> g(n+1), gr(n+1);
    int u,v; ll w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        gr[v].push_back({u,w});
    }
    vector<ll> T(d);
    for(int i=0;i<d;i++) cin>>T[i];
    
    vector<ll> dist1(n+1,INF), dist2(n+1,INF);
    dist1[1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [du,u]=pq.top(); pq.pop();
        if(du!=dist1[u]) continue;
        for(auto &e:g[u]){
            int v=e.first; ll c=e.second;
            if(dist1[v]>du+c){
                dist1[v]=du+c;
                pq.push({dist1[v],v});
            }
        }
    }
    
    dist2[n]=0;
    pq.push({0,n});
    while(!pq.empty()){
        auto [du,u]=pq.top(); pq.pop();
        if(du!=dist2[u]) continue;
        for(auto &e:gr[u]){
            int v=e.first; ll c=e.second;
            if(dist2[v]>du+c){
                dist2[v]=du+c;
                pq.push({dist2[v],v});
            }
        }
    }
    ll L = dist1[n];
    if(L>=INF){
        cout<<0<<"\n";
        return 0;
    }
    
    vector<ll> S;
    S.push_back(0);
    sort(T.begin(),T.end());
    for(ll t:T) if(t>0 && t<L) S.push_back(t);
    S.push_back(L);
    int P = S.size();
    
    vector<vector<int>> dag(n+1);
    for(int u=1;u<=n;u++){
        for(auto &e:g[u]){
            int v=e.first; ll c=e.second;
            if(dist1[u]+c+dist2[v]==L){
                dag[u].push_back(v);
            }
        }
    }
    
    vector<pair<ll,int>> nd;
    nd.reserve(n);
    for(int i=1;i<=n;i++){
        if(dist1[i]<INF) nd.push_back({dist1[i],i});
    }
    sort(nd.begin(),nd.end());
    vector<ll> dist_vals; dist_vals.reserve(nd.size());
    vector<int> nodes; nodes.reserve(nd.size());
    for(auto &pr:nd){
        dist_vals.push_back(pr.first);
        nodes.push_back(pr.second);
    }
    
    vector<int> dp(n+1), par(n+1);
    int ways_total = 1;
    vector<int> end_node(P-1,-1);
    int idx = 0;
    for(int seg=0;seg+1<P;seg++){
        ll Ld = S[seg], Rd = S[seg+1];
        int l = int(lower_bound(dist_vals.begin(),dist_vals.end(),Ld) - dist_vals.begin());
        int r = int(upper_bound(dist_vals.begin(),dist_vals.end(),Rd) - dist_vals.begin()) - 1;
        for(int i=l;i<=r;i++){
            dp[nodes[i]] = 0;
            par[nodes[i]] = -1;
        }
        
        for(int i=l;i<=r;i++){
            if(dist_vals[i]==Ld){
                dp[nodes[i]] = 1;
            }
        }
        
        for(int i=l;i<=r;i++){
            int x = nodes[i];
            if(dp[x]==0) continue;
            for(int y:dag[x]){
                if(dist1[y]>Rd) continue;
                int add = dp[x];
                dp[y] = min(dp[y] + add, 2);
                if(par[y]==-1 && add==1 && dp[y]==1){
                    par[y] = x;
                }else par[y] = -2;
            }
        }
        
        int cnt = 0, who = -1;
        for(int i=l;i<=r;i++){
            if(dist_vals[i]==Rd){
                int x = nodes[i];
                if(dp[x]>0){
                    cnt = min(cnt + dp[x], 2);
                    if(dp[x]==1 && who==-1) who = x;
                }
            }
        }
        if(cnt==0){
            cout<<0<<"\n";
            return 0;
        }
        ways_total = min(ways_total * cnt, 2);
        end_node[seg] = who;
    }
    if(ways_total>1){
        cout<<1<<"\n";
        return 0;
    }
    
    vector<int> path;
    int last = -1;
    for(int seg=0;seg<P-1;seg++){
        int cur = end_node[seg];
        vector<int> tmp;
        while(cur!=-1){
            tmp.push_back(cur);
            cur = par[cur];
        }
        reverse(tmp.begin(),tmp.end());
        if(!path.empty() && !tmp.empty() && path.back() == tmp.front()) {
            tmp.erase(tmp.begin());
        }
        for(int x:tmp) path.push_back(x);
    }
    cout<<path.size()<<"\n";
    for(int x:path) cout<<x<<"\n";
    return 0;
}
