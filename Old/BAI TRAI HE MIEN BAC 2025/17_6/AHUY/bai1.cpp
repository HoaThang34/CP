#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
#define int long long
#define task "sol"

int n;
vector<vector<int>> ke;

pair<int,int> bfs(int s){
    vector<int> d(n+1, -1);
    queue<int> q;
    d[s] = 0; q.push(s);
    int far = s, md = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : ke[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
                if(d[v] > md){
                    md = d[v];
                    far = v;
                }
            }
        }
    }
    return {far, md};
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    ke.assign(n+1, {});
    for(int i = 0, u, v; i < n-1; i++){
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    if(n <= 1){
        cout << 0 << "\n";
        return 0;
    }
    int u = bfs(1).first;
    int l = bfs(u).second;
    cout << l << "\n";
    return 0;
}
