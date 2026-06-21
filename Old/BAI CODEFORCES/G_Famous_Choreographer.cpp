#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
const int P1 = 31, P2 = 37;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
long long p1_pow[MAX], p2_pow[MAX];
void precompute_powers(){
    p1_pow[0] = p2_pow[0] = 1;
    for(int i = 1; i < MAX; ++i){
        p1_pow[i] = (p1_pow[i - 1] * P1) % MOD1;
        p2_pow[i] = (p2_pow[i - 1] * P2) % MOD2;
    }
}
struct Hash2D{
    int n, m;
    vector<vector<pair<long long, long long>>> h;
    Hash2D(const vector<string>& s){
        n = s.size();
        m = s[0].size();
        h.resize(n + 1, vector<pair<long long, long long>>(m + 1, {0, 0}));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                long long h1_term1 = (h[i][j + 1].first * P1) % MOD1;
                long long h1_term2 = (h[i + 1][j].first * P2) % MOD1;
                long long h1_sub_term = (h[i][j].first * P1) % MOD1;
                h1_sub_term = (h1_sub_term * P2) % MOD1;
                long long h1 = (h1_term1 + h1_term2 - h1_sub_term + s[i][j]);
                h[i + 1][j + 1].first = (h1 % MOD1 + MOD1) % MOD1;
                long long h2_term1 = (h[i][j + 1].second * P1) % MOD2;
                long long h2_term2 = (h[i + 1][j].second * P2) % MOD2;
                long long h2_sub_term = (h[i][j].second * P1) % MOD2;
                h2_sub_term = (h2_sub_term * P2) % MOD2;
                long long h2 = (h2_term1 + h2_term2 - h2_sub_term + s[i][j]);
                h[i + 1][j + 1].second = (h2 % MOD2 + MOD2) % MOD2;
            }
        }
    }
    pair<long long, long long> get(int r1, int c1, int r2, int c2){
        long long term11 = h[r2 + 1][c2 + 1].first;
        long long term12 = (h[r1][c2 + 1].first * p1_pow[r2 - r1 + 1]) % MOD1;
        long long term13 = (h[r2 + 1][c1].first * p2_pow[c2 - c1 + 1]) % MOD1;
        long long term14 = (h[r1][c1].first * p1_pow[r2 - r1 + 1]) % MOD1;
        term14 = (term14 * p2_pow[c2 - c1 + 1]) % MOD1;
        long long hash1 = (term11 - term12 - term13 + term14);
        hash1 = (hash1 % MOD1 + MOD1) % MOD1;
        long long term21 = h[r2 + 1][c2 + 1].second;
        long long term22 = (h[r1][c2 + 1].second * p1_pow[r2 - r1 + 1]) % MOD2;
        long long term23 = (h[r2 + 1][c1].second * p2_pow[c2 - c1 + 1]) % MOD2;
        long long term24 = (h[r1][c1].second * p1_pow[r2 - r1 + 1]) % MOD2;
        term24 = (term24 * p2_pow[c2 - c1 + 1]) % MOD2;
        long long hash2 = (term21 - term22 - term23 + term24);
        hash2 = (hash2 % MOD2 + MOD2) % MOD2;
        return {hash1, hash2};
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<string> b = a;
    for(int i = 0; i < n; ++i) reverse(b[i].begin(), b[i].end());
    reverse(b.begin(), b.end());
    Hash2D hA(a);
    Hash2D hB(b);
    long long best_k = 0, best_l = 0;
    for(int k = n; k >= 1; --k){
        int low = 1, high = m, max_l = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(hA.get(0, 0, k - 1, mid - 1) == hB.get(n - k, m - mid, n - 1, m - 1)){
                max_l = max(max_l, mid);
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(max_l > 0){
             long long cur_area = (2LL * n - k) * (2LL * m - max_l);
             long long best_area = (2LL * n - best_k) * (2LL * m - best_l);
             if(best_k == 0 || cur_area < best_area){
                best_k = k;
                best_l = max_l;
             }
        }
    }
    if(best_k == 0){
        best_k = n;
        best_l = m;
        cout << (long long)n * m << endl;
    } else {
        cout << (2LL*n - best_k)*(2LL*m - best_l) - (long long)n*m << endl;
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    precompute_powers();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}