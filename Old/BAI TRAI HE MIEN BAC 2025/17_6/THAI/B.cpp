#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"
const long long MOD = 1000000007;

long long n, m;
vector<long long>d;
ll modpow(ll a, ll e) {
    ll r = 1;
    while(e) {
        if(e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void subtask1() {
    vector<pair<long long,long long>> el;
    for(long long u = 1; u <= n; u++)
        for(long long v = u+1; v <= n; v++)
            el.emplace_back(u, v);
    long long E = el.size();
    vector<long long> sel(E, 0);
    for(long long i = 0; i < m; i++) sel[E-1-i] = 1;
    ll ans = 0;
    do {
        vector<vector<long long>> g(n+1);
        for(long long i = 0; i < E; i++) if(sel[i]) {
            auto &e = el[i];
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        vector<long long> dist(n+1, 1e9), ways(n+1,0);
        queue<long long> q;
        dist[1] = 0; ways[1] = 1; q.push(1);
        while(!q.empty()) {
            long long u = q.front(); q.pop();
            for(long long v: g[u]) {
                if(dist[v] == 1e9) {
                    dist[v] = dist[u] + 1;
                    ways[v] = ways[u];
                    q.push(v);
                } else if(dist[v] == dist[u] + 1) {
                    ways[v] = min(MOD, ways[v] + ways[u]);
                }
            }
        }
        bool ok = true;
        for(long long i = 1; i <= n; i++) {
            if(dist[i] != d[i] || ways[i] != 1) { ok = false; break; }
        }
        if(ok) ans++;
    } while(next_permutation(sel.begin(), sel.end()));
    cout << ans % MOD;
}

void subtask2() {
    vector<ll> cnt(*max_element(d.begin()+1, d.end())+1);
    for(long long i = 1; i <= n; i++) cnt[d[i]]++;
    ll ans = 1;
    for(size_t k = 1; k < cnt.size(); k++) {
        ans = ans * modpow(cnt[k-1], cnt[k]) % MOD;
    }
    cout << ans;
}

void subtask3() {
    vector<ll> cnt(*max_element(d.begin()+1, d.end())+1);
    for(long long i = 1; i <= n; i++) cnt[d[i]]++;
    ll treeWays = 1;
    for(size_t k = 1; k < cnt.size(); k++) {
        treeWays = treeWays * modpow(cnt[k-1], cnt[k]) % MOD;
    }
    ll rem = m - (n - 1);
    if(rem < 0) { cout << 0; return; }
    ll slots = 0;
    for(ll x: cnt) slots += x*(x-1)/2;
    ll opt = 1;
    for(ll i = 1; i <= rem; i++) {
        opt = opt * ((slots - i + 1) % MOD) % MOD;
        opt = opt * modpow(i, MOD-2) % MOD;
    }
    cout << treeWays * opt % MOD;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> m;
    d.assign(n+1,0);
    for(long long i = 1; i <= n; i++) cin >> d[i];
    subtask3();
    return 0;
}
