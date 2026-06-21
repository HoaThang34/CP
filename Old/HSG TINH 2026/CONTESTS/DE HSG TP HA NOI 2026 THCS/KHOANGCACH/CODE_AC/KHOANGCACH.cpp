#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Distance function between two chars on circle
int dist(int c1, int c2) {
    if (c1 > c2) swap(c1, c2);
    int d = c2 - c1;
    return min(d, 26 - d);
}

int main() {
    fast_io();
    if (fopen("KHOANGCACH.INP", "r")) {
        freopen("KHOANGCACH.INP", "r", stdin);
        freopen("KHOANGCACH.OUT", "w", stdout);
    }

    string S;
    int Q;
    if (cin >> S >> Q) {
        int N = S.length();
        // Prefix count for each character 'a'...'z'
        // P[char][i] = count of 'char' in S[0..i-1]
        vector<vector<int>> P(26, vector<int>(N + 1, 0));
        
        for (int i = 0; i < N; ++i) {
            for (int c = 0; c < 26; ++c) {
                P[c][i+1] = P[c][i];
            }
            P[S[i] - 'a'][i+1]++;
        }

        while (Q--) {
            int L, R;
            cin >> L >> R;
            // 1-based index in problem to 0-based
            L--; R--; // Range [L, R] inclusive

            // Identify present characters
            vector<int> present;
            for (int c = 0; c < 26; ++c) {
                // Count in range [L, R] is P[c][R+1] - P[c][L]
                if (P[c][R+1] - P[c][L] > 0) {
                    present.push_back(c);
                }
            }

            if (present.size() <= 1) {
                cout << 0 << "\n";
            } else {
                int max_d = 0;
                // Check all pairs. 26^2 is small.
                for (size_t i = 0; i < present.size(); ++i) {
                    for (size_t j = i + 1; j < present.size(); ++j) {
                        max_d = max(max_d, dist(present[i], present[j]));
                    }
                }
                cout << max_d << "\n";
            }
        }
    }
    return 0;
}
