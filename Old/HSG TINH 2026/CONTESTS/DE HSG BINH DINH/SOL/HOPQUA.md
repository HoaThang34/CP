# Giải thuật: HOPQUA

## Phân tích bài toán
Có $n$ hộp quà với các kích thước trong mảng $A$, và $m$ yêu cầu gói quà với kích thước tối thiểu cần thiết là $B$.
Mỗi hộp quà chỉ dùng cho tối đa 1 yêu cầu.
Cần chọn các hộp quà sao cho đáp ứng được $m$ yêu cầu và tổng kích thước các hộp được chọn là nhỏ nhất. Nếu không thể đáp ứng đủ $m$ yêu cầu thì in ra -1.

**Input:**
- Dòng đầu: $n, m$
- Dòng 2: Mảng $A$ (kích thước hộp)
- Dòng 3: Mảng $B$ (kích thước yêu cầu)

**Output:**
- Tổng kích thước nhỏ nhất hoặc -1.

## Thuật toán
Đây là bài toán tham lam (Greedy).
Để tối ưu tổng kích thước, với mỗi yêu cầu, ta nên chọn hộp quà nhỏ nhất có thể mà vẫn thõa mãn điều kiện (lớn hơn hoặc bằng kích thước yêu cầu).

Các bước:
1. Sắp xếp mảng $A$ tăng dần.
2. Sắp xếp mảng $B$ tăng dần.
3. Duyệt qua từng yêu cầu $B[i]$:
   - Tìm hộp $A[j]$ nhỏ nhất sao cho $A[j] \ge B[i]$ và chưa được sử dụng.
   - Do cả 2 mảng đã sắp xếp, ta có thể dùng kỹ thuật 2 con trỏ.

**Độ phức tạp:** $O(n \log n + m \log m)$.

## Cài đặt (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace Full {
    void solve(int n, int m, vector<long long>& A, vector<long long>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int ptr_a = 0;
        int matches = 0;
        long long total_cost = 0;

        for (int i = 0; i < m; i++) {
            long long req = B[i];
            
            // Find first box >= req
            while (ptr_a < n && A[ptr_a] < req) {
                ptr_a++;
            }

            if (ptr_a < n) {
                // Match found
                total_cost += A[ptr_a];
                matches++;
                ptr_a++; // Use this box
            } else {
                // No more boxes large enough
                cout << -1 << endl;
                return;
            }
        }

        if (matches == m) {
            cout << total_cost << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> A(n);
    vector<long long> B(m);

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    // Chỉ có 1 cách giải tối ưu cho cả subtask nhỏ và lớn
    Full::solve(n, m, A, B);

    return 0;
}
```
