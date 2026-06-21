#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<vector<long long>> a;
vector<bool> vs;
vector <long long> p;
vector <long long> ans;

bool dfs(long long u){
    vs[u] = true;
    for (auto v : a[u]){
        if (v == p[u]) continue;
        else if (!vs[v]){
            p[v] = u;
            if (dfs(v)){
                return true;
            }
        }
        else{
            ans.push_back(v);
            long long x=u;
            while(x!=v){
                ans.push_back(x);
                x=p[x]; 
            }
            ans.push_back(v);
            reverse(ans.begin(),ans.end());
            return true;
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    a.resize(n + 1);
    vs.resize(n + 1, 0);
    p.resize(n + 1);

    
    for (int i = 1; i <= m; i++){
        long long u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++){
        if (!vs[i]){
            if (dfs(i)){
                cout << ans.size() << endl;
                for (auto x : ans){
                    cout << x << " ";
                }
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}