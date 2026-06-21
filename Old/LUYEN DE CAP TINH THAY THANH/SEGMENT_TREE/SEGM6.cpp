/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEGM6"

// Compress values
vector<int> vals;
int get_id(int v) {
    return lower_bound(vals.begin(), vals.end(), v) - vals.begin() + 1;
}

const int MAXN = 100005;
const int MAX_NODES = 20000000; // 20M nodes approx. 
// If memory is tight, we might need manual management or optimize.
// But 20M * 12B = 240MB. Should be safe.

struct Node {
    int l, r;
    int sum;
} tree[MAX_NODES];
int cnt_nodes = 0;

int n, q;
int a[MAXN];
int bit_roots[MAXN]; // Roots for BIT

// Standard inputs
struct Query {
    int type, l, r, k, i, v;
} queries[MAXN];

void update_st(int &node, int start, int end, int idx, int val) {
    if (!node) node = ++cnt_nodes;
    tree[node].sum += val;
    if (start == end) return;
    int mid = (start + end) / 2;
    if (idx <= mid) update_st(tree[node].l, start, mid, idx, val);
    else update_st(tree[node].r, mid + 1, end, idx, val);
}

void update_bit(int idx, int val_idx, int delta) {
    for (; idx <= n; idx += idx & -idx) {
        update_st(bit_roots[idx], 1, vals.size(), val_idx, delta);
    }
}

// Helper to sum from vector of roots
int get_sum(const vector<int>& roots, bool is_left) {
    int sum = 0;
    for (int node : roots) {
        if (is_left) sum += tree[tree[node].l].sum;
        else sum += tree[tree[node].r].sum; // Actually not used this way usually
    }
    return sum;
}

// We need to descend simultaneously
// Query K-th LARGEST. 
// If we map values sort ascending: 1..M.
// K-th largest means (Total - K + 1)-th smallest?
// Or we can just build ST on values, then go Right if sum_right >= k.
// Yes. To find K-th largest:
// Check right child sum. 
// If sum_right >= k, go right.
// Else k -= sum_right, go left.

int query_bit(int l, int r, int k) {
    // Current roots
    vector<int> roots_r, roots_l;
    for (int i = r; i > 0; i -= i & -i) roots_r.push_back(bit_roots[i]);
    for (int i = l - 1; i > 0; i -= i & -i) roots_l.push_back(bit_roots[i]);

    int start = 1, end = vals.size();
    
    // Check total elements in range
    // sum is query_st(roots_r) - query_st(roots_l)
    // But we do it level by level.
    
    while (start < end) {
        int mid = (start + end) / 2;
        int right_sum = 0;
        
        // Sum of right children
        for (int node : roots_r) right_sum += tree[tree[node].r].sum;
        for (int node : roots_l) right_sum -= tree[tree[node].r].sum;
        
        if (right_sum >= k) {
            start = mid + 1;
            // Move pointers to right children
            for (int &node : roots_r) node = tree[node].r;
            for (int &node : roots_l) node = tree[node].r;
        } else {
            k -= right_sum;
            end = mid;
            // Move pointers to left children
            for (int &node : roots_r) node = tree[node].l;
            for (int &node : roots_l) node = tree[node].l;
        }
    }
    return vals[start - 1];
}

void hoathang(){
    if(!(cin >> n)) return;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    }
    cin >> q;
    for (int j = 0; j < q; j++) {
        cin >> queries[j].type;
        if (queries[j].type == 1) {
            cin >> queries[j].i >> queries[j].v;
            vals.push_back(queries[j].v);
        } else {
            cin >> queries[j].l >> queries[j].r >> queries[j].k;
        }
    }

    // Coordinate Compression
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    // Build initial
    for (int i = 1; i <= n; i++) {
        update_bit(i, get_id(a[i]), 1);
    }
    
    // Process queries
    for (int j = 0; j < q; j++) {
        if (queries[j].type == 1) {
            int idx = queries[j].i;
            int new_val = queries[j].v;
            int old_val = a[idx];
            update_bit(idx, get_id(old_val), -1);
            update_bit(idx, get_id(new_val), 1);
            a[idx] = new_val;
        } else {
            cout << query_bit(queries[j].l, queries[j].r, queries[j].k) << endl;
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
