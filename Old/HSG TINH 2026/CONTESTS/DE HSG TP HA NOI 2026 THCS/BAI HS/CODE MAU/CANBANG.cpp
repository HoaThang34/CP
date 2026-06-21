#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    if (fopen("CANBANG.INP", "r")) {
        freopen("CANBANG.INP", "r", stdin);
        freopen("CANBANG.OUT", "w", stdout);
    }

    int N;
    long long K;
    if (cin >> N >> K) {
        vector<long long> A(N);
        unordered_set<long long> S;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            S.insert(A[i]);
        }

        int count = 0;
        for (long long val : A) {
            if (S.count(val - K) && S.count(val + K)) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
