# Giải thuật: MATTHU

## Phân tích bài toán
Cho dãy số $A$ ban đầu. Thực hiện $m$ truy vấn thuộc 3 loại:
1. Tính tổng đoạn $[l, r]$.
2. Gán $A[i] = A[i] \pmod w$ với mọi $i$ trong $[l, r]$.
3. Gán $A[x] = k$.

**Input:**
- $n, m$
- Dãy $A$
- Các truy vấn

**Output:**
- Kết quả truy vấn loại 1.

## Thuật toán
Sử dụng Cấu trúc dữ liệu Segment Tree.
- Mỗi nút quản lý đoạn $[L, R]$, lưu `sum` (tổng) và `max` (giá trị lớn nhất).
- **Truy vấn 1 (Tổng):** Lấy `sum` từ Segment Tree bình thường.
- **Truy vấn 3 (Gán điểm):** Cập nhật điểm bình thường, cập nhật lại `sum` và `max` lên trên.
- **Truy vấn 2 (Modulo đoạn):**
  - Nhận xét: $x \pmod w$ chỉ làm thay đổi giá trị $x$ nếu $x \ge w$. Nếu $x < w$ thì $x \pmod w = x$.
  - Hơn nữa, mỗi lần lấy modulo, giá trị giảm đi đáng kể (ít nhất là giảm một nửa nếu $x > w$). Do đó số lần cập nhật thực tế trên mỗi phần tử không nhiều.
  - Ta có thể duyệt xuống cây để cập nhật. Tại mỗi nút, nếu `tree_max[node] < w` thì không cần đi sâu vào nút con đó nữa (vì tất cả phần tử trong đoạn đều nhỏ hơn $w$, phép modulo không tác dụng).
  - Độ phức tạp mỗi lần update dần dần sẽ về 0.

**Độ phức tạp:** $O(m \log n \cdot \log(\text{MaxVal}))$.

## Cài đặt (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace Full {
    const int MAXN = 200005;
    long long tree_sum[4 * MAXN];
    long long tree_max[4 * MAXN];

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

    // Luôn dùng Full cho tối ưu
    Full::solve(n, m, A);

    return 0;
}
```
