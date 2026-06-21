#include <bits/stdc++.h>
using namespace std;
// khai báo biến
// chia subtask
#define task "sol"
int n,m,k;
vector<vector<pair<int,int>>> g;
vector<bool> vs;
vector<long long> best;
void dfs(int u, long long cost){
    if(u==n){
        best.push_back(cost);
        if((int)best.size()>k){
            sort(best.begin(), best.end());
            best.pop_back();
        }
        return;
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(!vs[v]){
            if((int)best.size()==k && cost + w >= *max_element(best.begin(), best.end())) continue;
            vs[v]=true;
            dfs(v, cost + w);
            vs[v]=false;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>n>>m>>k;
    g.assign(n+1, {});
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vs.assign(n+1,false);
    vs[1]=true;
    dfs(1, 0);
    sort(best.begin(), best.end());
    for(int i=0;i<best.size();i++){
        cout<<best[i]<<(i+1<best.size()?' ':'\n');
    }
    return 0;
}
