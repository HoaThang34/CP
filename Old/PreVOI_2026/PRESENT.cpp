/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

const int SZ = 600005;
#define endl '\n'
#define nap "PRESENT"

int n, q;
string s;

struct Node {
    int mn, mx, lz;
} t[4 * SZ];

void push(int id) {
    if (t[id].lz) {
        swap(t[id * 2].mn, t[id * 2].mx);
        t[id * 2].mn ^= 1; t[id * 2].mx ^= 1;
        t[id * 2].lz ^= 1;

        swap(t[id * 2 + 1].mn, t[id * 2 + 1].mx);
        t[id * 2 + 1].mn ^= 1; t[id * 2 + 1].mx ^= 1;
        t[id * 2 + 1].lz ^= 1;

        t[id].lz = 0;
    }
}

void build(int id, int l, int r, const vector<int>& a) {
    if (l == r) {
        t[id] = {a[l], a[l], 0};
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m, a);
    build(id * 2 + 1, m + 1, r, a);
    t[id].mn = min(t[id * 2].mn, t[id * 2 + 1].mn);
    t[id].mx = max(t[id * 2].mx, t[id * 2 + 1].mx);
}

void up(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        swap(t[id].mn, t[id].mx);
        t[id].mn ^= 1; t[id].mx ^= 1;
        t[id].lz ^= 1;
        return;
    }
    push(id);
    int m = (l + r) / 2;
    up(id * 2, l, m, u, v);
    up(id * 2 + 1, m + 1, r, u, v);
    t[id].mn = min(t[id * 2].mn, t[id * 2 + 1].mn);
    t[id].mx = max(t[id * 2].mx, t[id * 2 + 1].mx);
}

int get(int id, int l, int r, int p) {
    if (l == r) return t[id].mn;
    push(id);
    int m = (l + r) / 2;
    if (p <= m) return get(id * 2, l, m, p);
    return get(id * 2 + 1, m + 1, r, p);
}

int fxt(int id, int l, int r, int p, int v) {
    if (l > r || t[id].mn > v || t[id].mx < v || r < p) return -1;
    if (l == r) return l;
    push(id);
    int m = (l + r) / 2;
    int res = fxt(id * 2, l, m, p, v);
    if (res != -1) return res;
    return fxt(id * 2 + 1, m + 1, r, p, v);
}

int fpv(int id, int l, int r, int p, int v) {
    if (l > r || t[id].mn > v || t[id].mx < v || l > p) return -1;
    if (l == r) return l;
    push(id);
    int m = (l + r) / 2;
    int res = fpv(id * 2 + 1, m + 1, r, p, v);
    if (res != -1) return res;
    return fpv(id * 2, l, m, p, v);
}

void hoathang(){
    if (!(cin >> n >> q)) return;
    cin >> s;
    vector<int> a(3 * n + 1);
    for (int i = 0; i < n; i++) {
        int v = (s[i] == '>');
        a[i + 1] = a[i + 1 + n] = a[i + 1 + 2 * n] = v;
    }
    int msz = 3 * n;
    build(1, 1, msz, a);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            up(1, 1, msz, l, r);
            up(1, 1, msz, l + n, r + n);
            up(1, 1, msz, l + 2 * n, r + 2 * n);
        } else {
            int x, k; cin >> x >> k;
            if (k == 1) {
                cout << x << endl;
                continue;
            }
            int L = x + n, R = x + n;
            int act = get(1, 1, msz, R);
            k--;

            while (k > 0) {
                int vR = get(1, 1, msz, R);
                int vL = get(1, 1, msz, L);

                if (vR == 0 && vL == 1) {
                    int nx = fxt(1, 1, msz, R + 1, 1);
                    int pr = fpv(1, 1, msz, L - 1, 0);
                    if (nx == -1) nx = msz + 1;
                    if (pr == -1) pr = 0;

                    int step = min({(nx - R), (L - pr), k / 2});

                    if (step > 0) {
                        R += step; L -= step;
                        k -= 2 * step;
                        vR = get(1, 1, msz, R);
                        vL = get(1, 1, msz, L);
                    }
                }

                if (k <= 0) break;

                if (act == 1) {
                    if (vR == 1) {
                        int nx = fxt(1, 1, msz, R + 1, 0);
                        if (nx == -1) nx = msz + 1;
                        int step = min(k, nx - R);
                        R += step; k -= step;
                        if (k > 0) act = 0;
                    } else {
                        L--; k--; act = 0;
                    }
                } else {
                    if (vL == 0) {
                        int pr = fpv(1, 1, msz, L - 1, 1);
                        if (pr == -1) pr = 0;
                        int step = min(k, L - pr);
                        L -= step; k -= step;
                        if (k > 0) act = 1;
                    } else {
                        R++; k--; act = 1;
                    }
                }
            }

            int ans = (act == 1) ? R : L;
            ans = (ans - 1) % n + 1;
            cout << ans << endl;
        }
    }
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
