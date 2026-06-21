/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

#define nap "DOANTOT"

const int M = 1e9 + 7;
ll res = 1;

struct N {
    int l, r, s;
    bool operator<(const N& o) const {
        return l < o.l;
    }
};

set<N> S;

ll pw(ll a, ll b) {
    ll r = 1;
    a %= M;
    while (b) {
        if (b & 1) r = (r * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return r;
}

ll inv(ll n) {
    return pw(n, M - 2);
}

void hoathang(){
    int n;
    cin >> n;
    while(n--){
        int u, v;
        cin >> u >> v;
        int ns = 1;
        auto it = S.lower_bound({u, -1, 0});
        if (it != S.begin()) --it;

        while (it != S.end() && it->l <= v) {
            if (it->r < u) {
                it++;
                continue;
            }
            u = min(u, it->l);
            v = max(v, it->r);
            ns += it->s;
            res = (res * inv(it->s)) % M;
            it = S.erase(it);
        }
        S.insert({u, v, ns});
        res = (res * (ns % M)) % M;
        cout << res << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
