/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "repaint"

long long n, m;
vector<int> c, d;
vector<vector<int>> g;
vector<int> col;

void hoathang(){
    cin >> n >> m;

    c.resize(n + 5);
    d.resize(n + 5);
    g.resize(n + 5);
    col.resize(n + 5, -1);

    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long ans = 0;
    const int INF = 1e9;

    for(int i = 1; i <= n; i++){
        if(col[i] == -1){
            vector<int> nodes;
            queue<int> q;
            bool ok = true;

            q.push(i);
            col[i] = 0;
            nodes.push_back(i);

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : g[u]){
                    if(col[v] == -1){
                        col[v] = 1 - col[u];
                        q.push(v);
                        nodes.push_back(v);
                    } else if(col[v] == col[u]){
                        ok = false;
                    }
                }
            }

            if(!ok){
                cout << -1 << endl;
                return;
            }

            long long c1 = 0, c2 = 0;

            for(int node : nodes){
                if(col[node] == 0){
                    if(c[node] == 2){
                        if(d[node] == 1) c1++; else c1 = INF;
                    }
                    if(c[node] == 1){
                        if(d[node] == 1) c2++; else c2 = INF;
                    }
                } else {
                    if(c[node] == 1){
                        if(d[node] == 1) c1++; else c1 = INF;
                    }
                    if(c[node] == 2){
                        if(d[node] == 1) c2++; else c2 = INF;
                    }
                }
            }
            
            long long res = min(c1, c2);
            if(res >= INF){
                cout << -1 << endl;
                return;
            }
            ans += res;
        }
    }

    cout << ans << endl;
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