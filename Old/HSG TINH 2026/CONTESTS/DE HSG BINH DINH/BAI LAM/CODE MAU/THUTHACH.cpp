#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

namespace Subtask1 {
    void solve(long long k, long long a, long long b) {
        long long count = 0;
        long long x = 1;
        while (true) {
            if (x % a != 0 && x % b != 0) {
                count++;
            }
            if (count == k) {
                cout << x << "\n";
                return;
            }
            x++;
        }
    }
}

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
        
        long long low = 1, high = 4000000000000000000LL; 
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

void solve_test_case() {
    long long k, a, b;
    cin >> k >> a >> b;
    
    // Chia theo ràng buộc
    // Subtask 1: K, a, b <= 100 (tuy nhiên a, b có thể đến 100 trong subtask 1)
    if (k <= 100 && a <= 100 && b <= 100) {
        Subtask1::solve(k, a, b);
    } else {
        Full::solve(k, a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve_test_case();
        }
    }
    return 0;
}
