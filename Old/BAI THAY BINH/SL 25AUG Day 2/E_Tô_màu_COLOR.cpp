#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
vector<long long> color;
vector<vector<long long>> g;
vector<vector<long long>> par;
void build(long long u, long long cha){
    for(long long v : g[u]){
        if(v != cha){
            par[u].push_back(v);
            build(v, u);
        }
    }
}
void subtask1(){
    par.resize(n + 1);
    build(1, 0);
    while(q--){
        long long loai;
        cin >> loai;
        if(loai == 1){
            long long u;
            cin >> u;
            vector<bool> vs(m + 1, false);
            queue<long long> q;
            q.push(u);
            vs[color[u]] = true;
            while(!q.empty()){
                long long dinh = q.front();
                q.pop();
                for(long long par : par[dinh]){
                    vs[color[par]] = true;
                    q.push(par);
                }
            }
            long long d = 0;
            for(long long i = 1; i <= m; ++i){
                if(vs[i]){
                    d++;
                }
            }
            cout << d << endl;
        }
        else{
            long long u, k;
            cin >> u >> k;
            color[u] = k;
        }
    }
}
#define task "COLOR"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> q;
    color.resize(n + 1);
    g.resize(n + 1);
    for(long long i = 1; i <= n; ++i){
        cin >> color[i];
    }
    for(long long i = 0; i < n - 1; ++i){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    subtask1();
    return 0;
}