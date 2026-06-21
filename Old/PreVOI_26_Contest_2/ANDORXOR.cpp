/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "ANDORXOR"

int n, m, s, r;
vector<int> c;
struct N {
    vector<int> z, o;
    int h;
};

N cb(const N &a, const N &b) {
    N res;
    res.h = (a.h + b.h) % n;
    res.z.resize(n);
    res.o.resize(n);
    for (int i = 0; i < n; ++i) {
        int j = (i + a.h);
        if (j >= n) j -= n;
        int bz = b.z[j];
        int bo = b.o[j];
        res.z[i] = (a.z[i] & bo) | (~a.z[i] & bz);
        res.o[i] = (a.o[i] & bo) | (~a.o[i] & bz);
    }
    return res;
}

void hoathang(){
    if(!(cin >> n >> m >> s >> r)) return;
    c.resize(n);
    for(int &x : c) cin >> x;
    vector<string> op(m);
    for(int i = 0; i < m; ++i) cin >> op[i];
    N b;
    b.z.assign(n, 0);
    b.o.assign(n, ~0);
    b.h = 0;
    int k = 0;
    for (const string &p : op) {
        k = (k + s);
        if (k >= n) k -= n;
        for (int i = 0; i < n; ++i) {
            int x = c[(i + k) >= n ? (i + k - n) : (i + k)];
            if (p == "xor") {
                b.z[i] ^= x;
                b.o[i] ^= x;
            } else if (p == "and") {
                b.z[i] &= x;
                b.o[i] &= x;
            } else {
                b.z[i] |= x;
                b.o[i] |= x;
            }
        }
    }
    b.h = k;
    N res;
    res.z.assign(n, 0);
    res.o.assign(n, ~0);
    res.h = 0;
    while (r > 0) {
        if (r & 1) res = cb(res, b);
        b = cb(b, b);
        r >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        int v = (c[i] & res.o[i]) | (~c[i] & res.z[i]);
        cout << v << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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
