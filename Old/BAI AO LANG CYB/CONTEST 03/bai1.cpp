/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
long long n, q;
vector <long long> a;
void sub1(){
    int l, r;
    cin >> l >> r;
    long long rmin = 1e18;
    for (int i = l; i <= r; i++)
        rmin = min(rmin, a[i]);
    cout << rmin << endl;
}
struct SegTree {
    long long n;
    vector<long long> st;
    SegTree(long long n) : n(n) {
        st.assign(4*n, 1e18);
    }
    void build(vector<long long> &a, long long id, long long l, long long r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        long long mid = (l + r) / 2;
        build(a, id*2, l, mid);
        build(a, id*2+1, mid+1, r);
        st[id] = min(st[id*2], st[id*2+1]);
    }
    long long query(long long id, long long l, long long r, long long u, long long v) {
        if (v < l || r < u) return 1e18;
        if (u <= l && r <= v) return st[id];
        long long mid = (l + r) / 2;
        long long leftVal = query(id*2, l, mid, u, v);
        long long rightVal = query(id*2+1, mid+1, r, u, v);
        return min(leftVal, rightVal);
    }
};
void sub2(){
    SegTree seg(n + 5);
    seg.build(a, 1, 1, n);
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << seg.query(1, 1, n, l, r) << endl;
    }
}
void hoathang(){
    cin >> n >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sub2();
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
