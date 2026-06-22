    /*
        author: hoaquangthang
    */

    #include <bits/stdc++.h>
    using namespace std;

    #define nap "DFS"
    #define endl '\n'
    #define int long long
    int n, m, s;
    vector <vector<int>> g;
    vector <bool> vs;
    void dfs(int u){
        vs[u] = true;
        cout << u << ' ';
        for (int v : g[u]){
            if (!vs[v]){
                dfs(v);
            }
        }
    }
    void hoathang(){
        cin >> n >> m >> s;
        g.resize(n + 5);
        vs.resize(n + 5, 0);
        for (int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++){
            sort(g[i].begin(), g[i].end());
        }
        dfs(s);
    }

    signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        if (fopen(nap".inp", "r")){
            freopen(nap".inp", "r", stdin);
            freopen(nap".out", "w", stdout);
        }

        hoathang();

        return 0;
    }
