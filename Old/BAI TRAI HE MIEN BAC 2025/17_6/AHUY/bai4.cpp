#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int n; cin>>n;
    vector<vector<pair<int,ll>>> ke(n+1);
    for(int i=1;i<n;i++){
        int u,v; ll w;
        cin>>u>>v>>w;
        ke[u].push_back({v,w});
        ke[v].push_back({u,w});
    }
    auto dfs = [&](int src, vector<ll>& dist){
        dist.assign(n+1, -1);
        stack<int> st;
        dist[src]=0;
        st.push(src);
        while(!st.empty()){
            int x=st.top(); st.pop();
            for(int i=0;i<ke[x].size();i++){
                int y=ke[x][i].first;
                ll cw=ke[x][i].second;
                if(dist[y]==-1){
                    dist[y]=dist[x]+cw;
                    st.push(y);
                }
            }
        }
        int node=src;
        for(int i=1;i<=n;i++)
            if(dist[i]>dist[node])
                node=i;
        return node;
    };
    vector<ll> distA, distB;
    int A = dfs(1, distA);
    int B = dfs(A, distA);
    dfs(B, distB);
    for(int i=1;i<=n;i++){
        cout<<max(distA[i], distB[i])<<" ";
    }
    return 0;
}
