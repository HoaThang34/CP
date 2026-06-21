#include <bits/stdc++.h>
using namespace std;
long long n, s;
vector <vector<long long>> g;
vector <long long> a;
vector <bool> vs;
long long ans = 0;
void dfs(long long u){
    vs[u] = true;
    ans = ans + a[u];
    for (long long v : g[u]){
        if (!vs[v]){
            dfs(v);
        }
    }
}
#define task "vutru"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> s;
    g.resize(n + 1);
    a.resize(n + 1);
    vs.resize(n + 1, false);
    for (int i = 1; i <= n; i++){
        long long p;
        cin >> a[i] >> p;
        if (p == 0 && a[i] > 0){
            s = s + a[i];
        }
        else{
            g[p].push_back(i);
        }
    }
    dfs(1);
    s = s + ans;
    cout << s;
    return 0;
}