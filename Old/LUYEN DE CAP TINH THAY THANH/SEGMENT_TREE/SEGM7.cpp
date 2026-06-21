/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEGM7"

const int INF = 2e9 + 7;
const int MAXN = 100005;
multiset<int> tree[4 * MAXN];
int a[MAXN];
int n, q;

void build(int node, int start, int end) {
    for(int i = start; i <= end; ++i) tree[node].insert(a[i]);
    // Optimization: This makes build O(N log^2 N).
    // Can we just insert without loop? 
    // No, multiset must contain all values in range.
    // Memory: N log N.
    if (start != end) {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
    }
}
// Actually the build above is O(N log N) depth * N width? No.
// Each element is inserted into log N multisets. Total insertions N log N.
// Complexity O(N log^2 N).

void update(int node, int start, int end, int idx, int old_val, int new_val) {
    if (idx < start || idx > end) return;
    auto it = tree[node].find(old_val);
    if(it != tree[node].end()) tree[node].erase(it);
    tree[node].insert(new_val);
    
    if (start != end) {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, idx, old_val, new_val);
        update(2 * node + 1, mid + 1, end, idx, old_val, new_val);
    }
}

int query(int node, int start, int end, int l, int r, int x) {
    if (r < start || end < l) return INF;
    if (l <= start && end <= r) {
        auto it = tree[node].lower_bound(x);
        if (it != tree[node].end()) return *it;
        return INF;
    }
    int mid = (start + end) / 2;
    return min(query(2 * node, start, mid, l, r, x),
               query(2 * node + 1, mid + 1, end, l, r, x));
}

void hoathang(){
    if(!(cin >> n)) return;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // Build manually to avoid deep recursion overhead?
    // Or just call insert for each element into all covering nodes.
    // Let's us the 'insert' pattern.
    auto add = [&](auto&& self, int node, int start, int end, int idx, int val) -> void {
        tree[node].insert(val);
        if (start == end) return;
        int mid = (start + end) / 2;
        if (idx <= mid) self(self, 2 * node, start, mid, idx, val);
        else self(self, 2 * node + 1, mid + 1, end, idx, val);
    };
    
    for(int i=1; i<=n; ++i) add(add, 1, 1, n, i, a[i]);
    
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, a[i], v);
            a[i] = v;
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            int res = query(1, 1, n, l, r, x);
            if (res == INF) cout << -1 << endl;
            else cout << res << endl;
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
