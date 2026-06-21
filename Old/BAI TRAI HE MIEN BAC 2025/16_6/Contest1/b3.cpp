#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"

ll n, q, l, r;
map<ll,ll> nt;

void pt(ll x){
    for (ll i = 2; i * i <= x; i++){
        if (x % i == 0){
            nt[i] = 1;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) nt[x] = 1;
}

void sub1(){
    ll d = 0;
    for (ll i = l; i <= r; i++){
        if (__gcd(i, n) == 1) d++;
    }
    cout << d << "\n";
}

void sub2(){
    vector<ll> a;
    for (auto [p, _] : nt) a.push_back(p);
    ll m = r - l + 1, res = 0, sz = a.size();
    for (ll mask = 1; mask < (1 << sz); mask++){
        ll t = 1, sl = 0;
        for (ll i = 0; i < sz; i++){
            if (mask >> i & 1){
                t *= a[i];
                sl++;
            }
        }
        ll dem = r / t - (l - 1) / t;
        if (sl % 2 == 1) res += dem;
        else res -= dem;
    }
    cout << m - res << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    cin >> n >> q;
    pt(n);
    while (q--){
        cin >> l >> r;
        // if (r - l + 1 <= 10000) sub1();
        // else sub2();
        sub2();
    }

    return 0;
}
