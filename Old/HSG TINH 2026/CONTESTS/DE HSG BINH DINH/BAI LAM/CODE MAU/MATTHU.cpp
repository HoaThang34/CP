#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace Subtask1 {
    void solve(int n, int m, vector<long long>& A) {
        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r;
                cin >> l >> r;
                long long sum = 0;
                for (int i = l; i <= r; i++) {
                    sum += A[i];
                }
                cout << sum << "\n";
            } else if (type == 2) {
                int l, r;
                long long w;
                cin >> l >> r >> w;
                for (int i = l; i <= r; i++) {
                    A[i] %= w;
                }
            } else if (type == 3) {
                int x;
                long long k;
                cin >> x >> k;
                A[x] = k;
            }
        }
    }
}

namespace Full {
    const int MAXN = 200005;
    long long tree_sum[4 * MAXN];
    long long tree_max[4 * MAXN];
    long long* A_ptr; // Pointer to access the array from build

    void build(int node, int start, int end, const vector<long long>& A) {
        if (start == end) {
            tree_sum[node] = A[start];
            tree_max[node] = A[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, A);
            build(2 * node + 1, mid + 1, end, A);
            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
        }
    }

    void update_point(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree_sum[node] = val;
            tree_max[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update_point(2 * node, start, mid, idx, val);
            } else {
                update_point(2 * node + 1, mid + 1, end, idx, val);
            }
            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
        }
    }

    void update_modulo(int node, int start, int end, int l, int r, long long k) {
        if (start > end || start > r || end < l || tree_max[node] < k) {
            return;
        }
        if (start == end) {
            tree_sum[node] %= k;
            tree_max[node] %= k;
            return;
        }
        int mid = (start + end) / 2;
        update_modulo(2 * node, start, mid, l, r, k);
        update_modulo(2 * node + 1, mid + 1, end, l, r, k);
        tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
        tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
    }

    long long query_sum(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree_sum[node];
        }
        int mid = (start + end) / 2;
        return query_sum(2 * node, start, mid, l, r) + query_sum(2 * node + 1, mid + 1, end, l, r);
    }

    void solve(int n, int m, vector<long long>& A) {
        build(1, 1, n, A);

        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r;
                cin >> l >> r;
                cout << query_sum(1, 1, n, l, r) << "\n";
            } else if (type == 2) {
                int l, r;
                long long w;
                cin >> l >> r >> w;
                update_modulo(1, 1, n, l, r, w);
            } else if (type == 3) {
                int x;
                long long k;
                cin >> x >> k;
                update_point(1, 1, n, x, k);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // Chia theo ràng buộc
    if (n <= 1000 && m <= 1000) {
        Subtask1::solve(n, m, A);
    } else {
        Full::solve(n, m, A);
    }

    return 0;
}
