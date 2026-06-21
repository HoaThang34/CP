#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long m, n, k;
vector <vector <long long>> a;
vector<vector<long long>> f;
void subtask1(){
    f.resize(m + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }
    long long ans = LLONG_MIN;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            for (int i1 = i; i1 <= m; i1++){
                for (int j1 = j; j1 <= n; j1++){
                    long long sum = f[i1][j1] - f[i-1][j1] - f[i1][j-1] + f[i-1][j-1];
                    if (sum <= k){
                        long long s = (i1 - i + 1) * (j1 - j + 1);
                        ans = max(ans, s);
                    }
                }
            }
        }
    }
    cout << ans;
}
void subtask2(){
    f.resize(m + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }
    long long ans = LLONG_MIN;
    for (int i = 1; i <= m; i++){
        for (int j = i; j <= m; j++){
            vector<long long> pre(n + 1, 0);
            for (int k = 1; k <= n; k++){
                pre[k] = f[j][k] - f[i-1][k] - f[j][k-1] + f[i-1][k-1];
            }
            long long sum = 0;
            int l = 1;
            for (int r = 1; r <= n; r++){
                sum += pre[r];
                while (sum > k && l <= r){
                    sum -= pre[l];
                    l++;
                }
                if (sum <= k){
                    long long s = (j - i + 1) * (r - l + 1);
                    ans = max(ans, s);
                }
            }
        }
    }
    cout << ans;
}
#define task "land"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    cin >> k;
    a.resize(m + 1, vector <long long> (n + 1));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (m <= 50 && n <= 50){
        subtask1();
    }
    else{
        subtask2();
    }
    // subtask1();
    // subtask2();
    return 0;
}