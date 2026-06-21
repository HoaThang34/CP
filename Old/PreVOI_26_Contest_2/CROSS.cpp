/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

void hoathang(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1);
    vector<int> bc;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
        if(d[i] != -1) bc.push_back(i);
    }

    auto bfs = [&](int s){
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : g[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    if(bc.empty()){
        cout << n << endl;
        for(int i = 1; i <= n; i++){
            cout << i << (i == n ? '\n' : ' ');
        }
        return;
    }

    int z = -1, cntz = 0;
    for(int b : bc){
        if(d[b] == 0){
            cntz++;
            z = b;
        }
    }
    if(cntz >= 2){
        cout << 0 << endl;
        return;
    }
    if(cntz == 1){
        auto dist = bfs(z);
        for(int b : bc){
            if(dist[b] != d[b]){
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl << z << endl;
        return;
    }

    int b0 = bc[0];
    auto dist0 = bfs(b0);
    vector<int> cand;
    cand.reserve(n);
    for(int i = 1; i <= n; i++){
        if(dist0[i] == d[b0] && d[i] == -1) cand.push_back(i);
    }

    if(cand.empty()){
        cout << 0 << endl;
        return;
    }

    int k = (int)bc.size();
    int limk = 450;

    auto fil = [&](int b, const vector<int>& dist){
        vector<int> nc;
        nc.reserve(cand.size());
        for(int x : cand){
            if(dist[x] == d[b]) nc.push_back(x);
        }
        cand.swap(nc);
    };

    if(k <= limk){
        for(int b : bc){
            auto dist = bfs(b);
            fil(b, dist);
            if(cand.empty()){
                cout << 0 << endl;
                return;
            }
        }
        cout << (int)cand.size() << endl;
        for(int i = 0; i < (int)cand.size(); i++){
            cout << cand[i] << (i + 1 == (int)cand.size() ? '\n' : ' ');
        }
        return;
    }

    vector<char> used(n + 1, 0);
    used[b0] = 1;
    int cur = b0;
    vector<int> distc = dist0;

    int lim = 35;
    for(int it = 0; it < lim; it++){
        int nb = -1, best = -1;
        for(int b : bc){
            if(!used[b] && distc[b] > best){
                best = distc[b];
                nb = b;
            }
        }
        if(nb == -1) break;
        used[nb] = 1;
        distc = bfs(nb);
        fil(nb, distc);
        if(cand.empty()){
            cout << 0 << endl;
            return;
        }
        if((int)cand.size() <= 80) break;
        cur = nb;
    }

    vector<int> ans;
    ans.reserve(cand.size());
    for(int x : cand){
        auto dist = bfs(x);
        bool ok = true;
        for(int b : bc){
            if(dist[b] != d[b]){
                ok = false;
                break;
            }
        }
        if(ok) ans.push_back(x);
    }

    cout << (int)ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
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
