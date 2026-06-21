#include <bits/stdc++.h>
using namespace std;
long long n, q;
string s;
vector<vector<long long>> g;
vector<vector<long long>> pos;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    cin >> s;
    s = " " + s;
    g.resize(n + 1);
    pos.resize(26);
    for(long long i = 1; i <= n; ++i){
        pos[s[i] - 'a'].push_back(i);
    }
    for(int i = 0; i < n - 1; ++i){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> q;
    while(q--){
        long long u, v;
        cin >> u >> v;
        if(u == v){
            cout << 0 << endl;
            continue;
        }
        vector<long long> dis(n + 1, -1);
        vector<bool> val(26, false);
        queue<long long> q;
        dis[u] = 0;
        q.push(u);
        long long ans = -1;
        while(!q.empty()){
            long long u = q.front();
            q.pop();
            if(u == v){
                ans = dis[v];
                break;
            }
            for(long long x : g[u]){
                if(dis[x] == -1){
                    dis[x] = dis[u] + 1;
                    q.push(x);
                }
            }
            long long color = s[u] - 'a';
            if(!val[color]){
                val[color] = true;
                for(long long x : pos[color]){
                    if(dis[x] == -1){
                        dis[x] = dis[u] + 1;
                        q.push(x);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}