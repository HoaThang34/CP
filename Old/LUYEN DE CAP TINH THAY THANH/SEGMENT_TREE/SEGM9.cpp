/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEGM9"

const int MAXN = 100005;

struct Node {
    bool is_sorted;
    int l_val, r_val;
} tree[4 * MAXN];

int a[MAXN];
int n, q;

Node merge(Node left, Node right) {
    Node res;
    res.l_val = left.l_val;
    res.r_val = right.r_val;
    res.is_sorted = left.is_sorted && right.is_sorted && (left.r_val < right.l_val);
    return res;
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {true, a[start], a[start]};
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx] = val;
        tree[node] = {true, val, val};
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

Node query(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    if (r <= mid) return query(2 * node, start, mid, l, r);
    if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);
    return merge(query(2 * node, start, mid, l, r),
                 query(2 * node + 1, mid + 1, end, l, r));
}

void hoathang(){
    if(!(cin >> n)) return;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, v);
        } else {
            int l, r;
            cin >> l >> r;
            if (query(1, 1, n, l, r).is_sorted) cout << "YES" << endl;
            else cout << "NO" << endl;
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
