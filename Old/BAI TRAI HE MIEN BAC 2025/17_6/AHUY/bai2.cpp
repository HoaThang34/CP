#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    ll n;
    cin>>n;
    vector<vector<ll>> ke(n+1);
    for(ll i=1,u,v;i<n;i++){
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    if(n==1){
        cout<<"0 1\n1\n";
        return 0;
    }
    vector<ll> trace(n+1);

    auto bfs_far=[&](ll s){
        vector<ll> dist(n+1, -1);
        queue<ll> q;
        q.push(s);
        dist[s]=0;
        trace.assign(n+1, 0);
        ll far=s, maxd=0;
        while(!q.empty()){
            ll u=q.front(); q.pop();
            for(ll v: ke[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    trace[v]=u;
                    if(dist[v]>maxd){
                        maxd=dist[v];
                        far=v;
                    }
                    q.push(v);
                }
            }
        }
        return far;
    };
    ll u=bfs_far(1);
    ll v=bfs_far(u);
    vector<ll> path;
    for(ll x=v; x!=u; x=trace[x]) path.push_back(x);
    path.push_back(u);
    reverse(path.begin(), path.end());
    ll D=path.size()-1;
    ll r = D/2;
    vector<ll> centers;
    if(D%2==0){
        centers.push_back(path[r]);
    } else {
        centers.push_back(path[r]);
        centers.push_back(path[r+1]);
        sort(centers.begin(), centers.end());
    }
    cout<<r<<" "<<centers.size()<<"\n";
    for(ll x: centers) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
