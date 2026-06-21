#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    
    if (fopen("XOADOAN.INP", "r")) {
        freopen("XOADOAN.INP", "r", stdin);
        freopen("XOADOAN.OUT", "w", stdout);
    }

    int N;
    long long S;
    if (cin >> N) {
        vector<long long> A(N);
        long long total_sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            total_sum += A[i];
        }
        cin >> S;

        if (total_sum <= S) {
            cout << 0 << endl;
            return 0;
        }

        long long K = total_sum - S;

        vector<long long> P(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            P[i+1] = P[i] + A[i];
        }

        deque<int> dq;
        int min_len = N + 1;

        for (int j = 0; j <= N; ++j) {
            while (!dq.empty() && P[j] - P[dq.front()] >= K) {
                min_len = min(min_len, j - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && P[dq.back()] >= P[j]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        if (min_len > N) {
            cout << -1 << endl;
        } else {
            cout << min_len << endl;
        }
    }
    return 0;
}
