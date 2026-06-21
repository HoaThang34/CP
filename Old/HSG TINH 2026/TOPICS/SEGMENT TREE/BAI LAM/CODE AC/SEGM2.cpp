#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Segment Tree for Range Minimum Query
// 1-based indexing for the array

const int MAXN = 100005;
const int INF = 2e9 + 7;
int st[4 * MAXN];
int a[MAXN];
int n, q;

// Build the Segment Tree
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

// Update value at position pos to val
void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        st[id] = val; // Assign new value
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * id, l, mid, pos, val);
    else
        update(2 * id + 1, mid + 1, r, pos, val);
    
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

// Get min in range [u, v]
int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return INF;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return min(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("SEGM2.inp", "r")) {
        freopen("SEGM2.inp", "r", stdin);
        freopen("SEGM2.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, v);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}
