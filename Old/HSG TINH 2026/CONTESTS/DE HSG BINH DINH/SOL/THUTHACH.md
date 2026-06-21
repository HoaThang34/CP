# Giải thuật: THUTHACH

## Phân tích bài toán
Tìm số nguyên dương thứ $k$ mà **không** chia hết cho $a$ và cũng **không** chia hết cho $b$.

**Input:**
- $t$ bộ test.
- Mỗi test: $k, a, b$.

**Output:**
- Số tìm được.

## Thuật toán
Đây là bài toán tìm kiếm nhị phân trên kết quả (Binary Search on Answer).
Hàm kiểm tra `check(x)`: Đếm số lượng số nguyên dương trong $[1, x]$ thỏa mãn điều kiện đề bài.
Nếu `check(mid) >= k`, ta lưu kết quả và thử tìm số nhỏ hơn (giảm `high`).
Ngược lại, tăng `low`.

**Cách tính `count_valid(x, a, b)`:**
Số lượng số $\le x$ chia hết cho $a$ là $\lfloor x/a \rfloor$.
Số lượng số $\le x$ chia hết cho $b$ là $\lfloor x/b \rfloor$.
Số lượng số $\le x$ chia hết cho cả $a$ và $b$ (tức là chia hết cho LCM($a, b$)) là $\lfloor x/\text{LCM}(a, b) \rfloor$.

Theo nguyên lý bù trừ, số lượng số $\le x$ **chia hết cho ít nhất một trong hai số** $a$ hoặc $b$ là:
$$ \text{div\_any} = \lfloor x/a \rfloor + \lfloor x/b \rfloor - \lfloor x/\text{LCM}(a, b) \rfloor $$

Số lượng số $\le x$ **không chia hết cho cả $a$ và $b$** là:
$$ \text{valid} = x - \text{div\_any} $$

**Giới hạn:** $k$ có thể rất lớn, nên Binary Search cần chạy đến khoảng $2 \cdot 10^{18}$ (số 64-bit).

**Độ phức tạp:** $O(t \cdot \log(\text{High}))$.

## Cài đặt (C++)

```cpp
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

namespace Full {
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        // cẩn thận tràn số nếu a*b quá lớn, nhưng đề bài thường cho a, b vừa phải hoặc k vừa phải
        // Ở đây a, b có thể tới 10^9 nên cần cẩn thận. Tuy nhiên logic bài này thường a, b nhỏ
        // Nếu a, b lớn thì LCM lớn, div_l = 0.
        // Để an toàn ta có thể xử lý __int128 hoặc check a / gcd * b
        return (a / gcd(a, b)) * b;
    }

    // Count numbers in [1, x] NOT divisible by a or b
    long long count_valid(long long x, long long a, long long b, long long l_val) {
        long long div_a = x / a;
        long long div_b = x / b;
        long long div_l = x / l_val;
        long long div_any = div_a + div_b - div_l;
        return x - div_any;
    }

    void solve(long long k, long long a, long long b) {
        long long l_val = lcm(a, b);
        
        long long low = 1, high = 4000000000000000000LL; // 4*10^18 tương đối an toàn
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count_valid(mid, a, b, l_val) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            long long k, a, b;
            cin >> k >> a >> b;
            Full::solve(k, a, b);
        }
    }
    return 0;
}
```
