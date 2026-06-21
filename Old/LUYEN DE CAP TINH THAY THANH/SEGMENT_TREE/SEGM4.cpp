/*
    author: hoaquangthang
    Solution: Square Root Decomposition (Chia căn)
    Complexity: O(Q * sqrt(N) * log(sqrt(N)))
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEGM8"

const int MAXN = 100005;
const int BLOCK_SIZE = 400; // tuned for N=10^5

int n, q;
int a[MAXN];
vector<int> blocks[MAXN / BLOCK_SIZE + 5];

int get_block_id(int idx) {
    return (idx - 1) / BLOCK_SIZE;
}

void build() {
    for (int i = 1; i <= n; i++) {
        blocks[get_block_id(i)].push_back(a[i]);
    }
    for (int i = 0; i <= get_block_id(n); i++) {
        sort(blocks[i].begin(), blocks[i].end());
    }
}

void update(int idx, int val) {
    int b_id = get_block_id(idx);
    int old_val = a[idx];
    
    // Remove old_val
    auto it = lower_bound(blocks[b_id].begin(), blocks[b_id].end(), old_val);
    blocks[b_id].erase(it);
    
    // Insert new val
    auto it2 = upper_bound(blocks[b_id].begin(), blocks[b_id].end(), val);
    blocks[b_id].insert(it2, val);
    
    a[idx] = val;
}

int query(int l, int r, int x, int y) {
    int sum = 0;
    int bl = get_block_id(l);
    int br = get_block_id(r);
    
    if (bl == br) {
        for (int i = l; i <= r; i++) {
            if (a[i] >= x && a[i] <= y) sum++;
        }
    } else {
        // Left partial
        for (int i = l; i <= (bl + 1) * BLOCK_SIZE; i++) {
            if (a[i] >= x && a[i] <= y) sum++;
        }
        
        // Right partial
        for (int i = br * BLOCK_SIZE + 1; i <= r; i++) {
            if (a[i] >= x && a[i] <= y) sum++;
        }
        
        // Middle blocks
        for (int b = bl + 1; b < br; b++) {
            // Count elements in [x, y]
            // upper_bound(y) - lower_bound(x)
            auto it1 = lower_bound(blocks[b].begin(), blocks[b].end(), x);
            auto it2 = upper_bound(blocks[b].begin(), blocks[b].end(), y);
            sum += (it2 - it1);
        }
    }
    return sum;
}

void hoathang(){
    if(!(cin >> n)) return;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    build();
    
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(i, v);
        } else {
            int l, r, x, y;
            cin >> l >> r >> x ;
            cout << query(l, r, x, x) << endl;
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
