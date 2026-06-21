#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
using namespace std;
#define ll long long
#define vtn 3004
#define fmax 1000007
#define fi first
#define se second
#define sp << " "
#define el << "\n"
#define oo 1e9
// #define int ll
#define pii pair<int,int>
#define pb push_back
#define FOD(i,b,a) for(int i = (int)b; i >= (int)a; i--)
#define FOR(i,a,b) for(int i = (int)a; i <= (int)b; i++)
#define NAME "TS"
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}
//0x3f = oo

int n, m, k;
vector<pii> q[fmax];
int tv[fmax];
int d[fmax];

void dfs(int u, int val){
    for(auto it: q[u]){
        int nval;
        if(u == 1) nval = it.se;
        nval = min(val, it.se);
        // cerr << it.fi sp << nval el;
        if(d[it.fi] < nval){
            d[it.fi] = nval;
            dfs(it.fi, nval);
        }
    }
}

void solve(){
    memset(d, 0,sizeof d);
    cin >> n >> m >> k;
    FOR(i,1,m){
        int u, v, w;
        cin >> u >> v >> w;
        q[u].pb({v,w});
        q[v].pb({u,w});
    }
    FOR(i,1,k) cin >> tv[i];
    d[1] = 1e9;
    dfs(1, 1e9);
    FOR(i,1,k)
    cout << d[tv[i]] sp;
}
signed main(){
    faster
    if(fopen(NAME".inp", "r")){
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    int test = 1;
    // cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
