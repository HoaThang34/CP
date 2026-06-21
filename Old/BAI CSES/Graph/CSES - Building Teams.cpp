/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n, m;
vector <vector <long long>> g;
vector <bool> vs;
void hoathang(){
    cin >> n >> m;
    g.resize(n + 5);
    vs.resize(n + 5, false);
    for (int i = 1; i <= m; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue <long long> q;
    vector <long long> color(n + 5, 1);
    color[1] = 1;
    for (int i = 1; i <= n; i++){
        if (vs[i] == false){
            vs[i] = true;
            q.push(i);
            while (!q.empty()){
                long long u = q.front(); q.pop();
                for (long long x : g[u]){
                    if (!vs[x]){
                        vs[x] = true;
                        color[x] = 3 - color[u];
                        q.push(x);
                    }
                    else if (color[x] == color[u]){
                        cout << "IMPOSSIBLE"<< endl;
                        return;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << color[i] << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
