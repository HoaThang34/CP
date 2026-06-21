#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    if (fopen("CHOXUAN.INP", "r")) {
        freopen("CHOXUAN.INP", "r", stdin);
        freopen("CHOXUAN.OUT", "w", stdout);
    }

    long long N, K;
    if (cin >> N >> K) {
        long long total_cost = K * 7;
        if (N >= total_cost) {
            cout << N - total_cost << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
