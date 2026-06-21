#include <bits/stdc++.h>
using namespace std;
long long m, n, x, y;
vector<vector<long long>> a;
const int MOD = 1e9 + 7;
void subtask1(){
    long long res = 1;
    for (int i = 1; i + x - 1 <= n; i++) {
        for (int j = 1; j + y - 1 <= m; j++) {
            set<long long> s;
            for (int k = i; k < i + x; k++) {
                for (int l = j; l < j + y; l++) {
                    s.insert(a[k][l]);
                }
            }
            long long k = 1;
            while (s.count(k)) k++;
            res = (res * k) % MOD;
        }
    }
    cout << res << "\n";
}
void subtask2(){
    long long res = 1;
    for (int i = 1; i + x - 1 <= n; i++) {
        vector<long long> cnt(1e6 + 10, 0); 
        for (int j = 1; j + y - 1 <= m; j++) {
            if (j == 1) {
                for (int k = i; k < i + x; k++) {
                    for (int l = j; l < j + y; l++) {
                        cnt[a[k][l]]++;
                    }
                }
            } else {
                for (int k = i; k < i + x; k++) {
                    cnt[a[k][j - 1]]--;
                    cnt[a[k][j + y - 1]]++;
                }
            }
            long long mex = 1;
            while (cnt[mex]) mex++;
            res = (res * mex) % MOD;
        }
    }
    cout << res << "\n";
}
void subtask3(){
    long long res = 1;
    int B = sqrt(n * m) + 1; 
    vector<int> cnt(1e6 + 10, 0);
    for (int i = 1; i + x - 1 <= n; i++) {
        fill(cnt.begin(), cnt.end(), 0);
        
        for (int k = i; k < i + x; k++) {
            for (int l = 1; l <= y; l++) {
                cnt[a[k][l]]++;
            }
        }
        
        long long mex = 1;
        while (cnt[mex]) mex++;
        res = (res * mex) % MOD;
        
        for (int j = 2; j + y - 1 <= m; j++) {
            for (int k = i; k < i + x; k++) {
                cnt[a[k][j - 1]]--;
                cnt[a[k][j + y - 1]]++;
            }
            long long mex = 1;
            while (cnt[mex]) mex++;
            res = (res * mex) % MOD;
        }
    }
    cout << res << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y;
    a.assign(n + 2, vector<long long>(m + 2)); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    subtask3();
    return 0;
}