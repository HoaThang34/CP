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
    if (n <= 2000) {
        Subtask1::solve(n, k, a);
    } else {
        Full::solve(n, k, a);
    }

    return 0;
}
