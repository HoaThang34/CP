#include <bits/stdc++.h>
using namespace std;
#define N 20

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("sol.inp", "r")){
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }
    int n;
    cin >> n;
    vector <vector <int>> a(n + 1, vector <int> (n + 1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    long long ans = 0;
    for(int i = 1; i < (1 << n); ++i){
        bool ok = true;
        int dem = __builtin_popcount(i);
        if (dem != n) continue;
        for(int j = 1; j <= n; ++j){
            if ((i >> (j - 1)) & 1 && !a[j][j]){
                ok = false;
                break;
            }
            if (!((i >> (j - 1)) & 1) && a[j][j]){
                ok = false;
                break;
            }
        }
        if (ok){
            ans++;
        }
    }
    cout << ans % 1000000007;
    return 0;
}