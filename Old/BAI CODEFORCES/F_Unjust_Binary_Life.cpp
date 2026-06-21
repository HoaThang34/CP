#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string a, b;
        cin >> a >> b;

        vector<long long> pa0(n+1), pa1(n+1), pb0(n+1), pb1(n+1);
        for(int i = 1; i <= n; i++){
            pa0[i] = pa0[i-1] + (a[i-1] == '0');
            pa1[i] = pa1[i-1] + (a[i-1] == '1');
            pb0[i] = pb0[i-1] + (b[i-1] == '0');
            pb1[i] = pb1[i-1] + (b[i-1] == '1');
        }

        long long ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                long long cntA0 = pa0[i];
                long long cntA1 = pa1[i];
                long long cntB0 = pb0[j];
                long long cntB1 = pb1[j];
                long long cost_to_all_zeros = cntA1 + cntB1;
                long long cost_to_all_ones  = cntA0 + cntB0;
                ans += min(cost_to_all_zeros, cost_to_all_ones);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
