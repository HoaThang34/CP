#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long n, m;
const int N = 1e6 + 7;
vector<ll> g[N];
vector <long long> a;
vector <bool> vs;
void dfs (long long u){
    vs[u] = true;
    for (long long v : g[u]){
        if (!vs[v]){
            dfs(v);
        }
    }
}
#define task "dothi"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    ll maxA=-1e18;
    for(int i=1;i<=n;i++) cin >> a[i], maxA = max(1ll * maxA, a[i]);
    vs.resize(n + 1, false);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            ll x=a[i] & a[j];
            if (x == 0){
                // cout << a[i] << " " << a[j] << endl;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int d = 0;
    for(int i=1;i<=n;i++) {
        if (!vs[i]){
            dfs(i);
            d++;
        }
    }
    cout << d;
    return 0;
}