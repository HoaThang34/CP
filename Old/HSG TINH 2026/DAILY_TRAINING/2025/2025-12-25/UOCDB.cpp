/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef __int128_t i128;

#define nap "UOCDB"

map<ll, int> mp;
vector<ll> v, ans;

ll mul(ll a, ll b, ll m) {
    return (ll)((i128)a * b % m);
}

ll pw(ll a, ll b, ll m) {
    ll r = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return r;
}

bool mr(ll n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) { d /= 2; s++; }
    static const vector<ll> b = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : b) {
        if (a >= n) break;
        ll x = pw(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool c = 1;
        for (int i = 1; i < s; i++) {
            x = mul(x, x, n);
            if (x == n - 1) { c = 0; break; }
        }
        if (c) return 0;
    }
    return 1;
}

ll pr(ll n) {
    if (n % 2 == 0) return 2;
    ll x = 2, y = 2, d = 1, c = 1;
    auto f = [&](ll v) { return (mul(v, v, n) + c) % n; };
    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = __gcd(x > y ? x - y : y - x, n);
        if (d == n) {
            x = rand() % (n - 2) + 2;
            y = x;
            c = rand() % (n - 1) + 1;
            d = 1;
        }
    }
    return d;
}

void fac(ll n) {
    if (n == 1) return;
    if (mr(n)) { mp[n]++; return; }
    ll d = pr(n);
    fac(d);
    fac(n / d);
}

void gen(map<ll, int>::iterator it, ll cur) {
    if (it == mp.end()) { v.push_back(cur); return; }
    ll p = it->first;
    int c = it->second;
    auto nit = next(it);
    ll pp = 1;
    for (int i = 0; i <= c; ++i) {
        gen(nit, cur * pp);
        if (i < c) pp *= p;
    }
}

void slv() {
    ll n;
    cin >> n;
    mp.clear(); v.clear(); ans.clear();
    fac(n);
    gen(mp.begin(), 1);
    for (ll d : v) {
        if (d == 0) continue;
        i128 del = (i128)1 + (i128)4 * d;
        ll k = sqrt((long double)del);
        if ((i128)k * k < del) k++;
        if ((i128)k * k > del) k--;
        if ((i128)k * k == del) {
            if ((k - 1) % 2 == 0) {
                ll x = (k - 1) / 2;
                if (x > 0) ans.push_back(x);
            }
        }
    }
    if (ans.empty()) cout << -1 << endl;
    else {
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        cout << endl;
    }
}

void hoathang(){
    int q;
    if(cin >> q) while(q--) slv();
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
