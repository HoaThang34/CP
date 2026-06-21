#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> g(n+1);
    int u,v;
    long long w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    const long long INF=LLONG_MAX;
    vector<vector<long long>> dist(n+1,vector<long long>(2,INF));
    dist[1][0]=0;
    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> q;
    q.push(make_tuple(0,1,0));
    long long d;
    int used;
    while(!q.empty()){
        tie(d,u,used)=q.top();
        q.pop();
        if(d>dist[u][used]) continue;
        for(size_t i=0;i<g[u].size();i++){
            int v2=g[u][i].first;
            long long w2=g[u][i].second;
            if(dist[v2][used]>d+w2){
                dist[v2][used]=d+w2;
                q.push(make_tuple(dist[v2][used],v2,used));
            }
            if(used==0){
                if(dist[v2][1]>d+w2/2){
                    dist[v2][1]=d+w2/2;
                    q.push(make_tuple(dist[v2][1],v2,1));
                }
            }
        }
    }
    cout<<dist[n][1];
    return 0;
}
