#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

// A robust function to check for perfect squares using long double for precision.
bool is_perfect_square(long long n) {
    if (n < 0) return false;
    if (n == 0) return true;
    long long root = round(sqrtl(n));
    return root * root == n;
}

void solve() {
    int n;
    std::cin >> n;

    if (n == 2) {
        std::cout << -1 << "\n";
        return;
    }

    // Precompute prefix sums for O(1) range sum queries.
    // prefix_sums[i] will store the sum of vertices from 1 to i.
    std::vector<long long> prefix_sums(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sums[i] = prefix_sums[i - 1] + i;
    }

    // Iterate through all possible partition points 'k'.
    for (int k = 1; k < n; ++k) {
        // Calculate the sum of products for the "double star" tree partitioned by k.
        long long current_S = 0;

        // Sum for the first star (center k, leaves 1 to k-1)
        if (k > 1) {
            current_S += (long long)k * prefix_sums[k - 1];
        }

        // Sum for the second star (center k+1, leaves k+2 to n)
        if (k + 2 <= n) {
            long long sum_of_leaves_B = prefix_sums[n] - prefix_sums[k + 1];
            current_S += (long long)(k + 1) * sum_of_leaves_B;
        }

        // Add the product for the connecting edge.
        current_S += (long long)k * (k + 1);

        if (is_perfect_square(current_S)) {
            // Found a beautiful tree. Print the edges and return.
            if (k > 1) {
                for (int i = 1; i < k; ++i) {
                    std::cout << i << " " << k << "\n";
                }
            }
            if (k + 2 <= n) {
                for (int j = k + 2; j <= n; ++j) {
                    std::cout << j << " " << k + 1 << "\n";
                }
            }
            std::cout << k << " " << k + 1 << "\n";
            return;
        }
    }
    
    // This part should not be reached for n > 2 with this construction,
    // but is good practice to include.
    std::cout << -1 << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}