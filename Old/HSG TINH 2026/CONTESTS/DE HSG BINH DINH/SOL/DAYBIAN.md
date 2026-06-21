# Giải thuật: DAYBIAN

## Phân tích bài toán
Cho dãy số $A$ gồm $n$ phần tử và một số nguyên $k$. Yêu cầu đếm số lượng dãy con liên tiếp có tổng bằng $k$.

**Input:**
- Dòng đầu: $n, k$
- Dòng sau: dãy $A$

**Output:**
- Số lượng dãy con có tổng bằng $k$.

## Thuật toán
Sử dụng kỹ thuật Mảng cộng dồn (Prefix Sum) kết hợp với Hash Map (hoặc mảng đếm nếu giá trị nhỏ).

Gọi $S[i]$ là tổng tiền tố từ $A[1]$ đến $A[i]$ ($S[0] = 0$).
Tổng của dãy con từ $j$ đến $i$ là $S[i] - S[j-1]$.
Ta cần đếm số cặp $(j, i)$ sao cho $S[i] - S[j-1] = k$, hay $S[j-1] = S[i] - k$.

Duyệt qua từng vị trí $i$ từ $1$ đến $n$:
1. Tính $S[i] = S[i-1] + A[i]$.
2. Cộng số lượng các tiền tố trước đó có giá trị bằng $S[i] - k$ vào kết quả.
3. Thêm $S[i]$ vào map đếm.

**Độ phức tạp:** $O(n \log n)$ hoặc $O(n)$ tùy thuộc vào cấu trúc dữ liệu Map.

## Cài đặt (C++)

```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace Subtask1 {
    void solve(int n, long long k, const vector<long long>& a) {
        long long count = 0;
        for (int i = 0; i < n; i++) {
            long long current_sum = 0;
            for (int j = i; j < n; j++) {
                current_sum += a[j];
                if (current_sum == k) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

namespace Full {
    void solve(int n, long long k, const vector<long long>& a) {
        map<long long, int> prefix_counts;
        prefix_counts[0] = 1; 
        
        long long current_sum = 0;
        long long ans = 0;

        for (long long x : a) {
            current_sum += x;
            long long target = current_sum - k;
            if (prefix_counts.count(target)) {
                ans += prefix_counts[target];
            }
            prefix_counts[current_sum]++;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Chia theo ràng buộc
    // Subtask 1 thường là n nhỏ, có thể dùng O(n^2)
    // Full dùng O(n log n)
    Full::solve(n, k, a);

    return 0;
}
```
