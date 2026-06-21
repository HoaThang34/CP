#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector<long long> a;
vector<vector<long long>> g;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> q;
    a.resize(n + 1);
    g.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while (q--){
        long long loai;
        cin >> loai;
        if (loai == 1){
            long long u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        else{
            long long u, c;
            cin >> u >> c;
            long long d = 0;
            vector<bool> vs(n + 1, false);
            queue<long long> q;
            q.push(u);
            vs[u] = true;
            while(!q.empty()){
                long long v = q.front();
                q.pop();
                if (a[v] == c){
                    d++;
                }
                for (long long t : g[v]){
                    if (!vs[t]){
                        vs[t] = true;
                        q.push(t);
                    }
                }
            }
            cout << d << endl;
        }
    }
    return 0;
}