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
