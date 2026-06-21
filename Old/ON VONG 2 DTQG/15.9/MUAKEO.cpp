#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> l, r;
#define task "MUAKEO"
void subtask1(){
    cin >> n;
    l.assign(n + 1, 0);
    r.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    vector<long long> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        long long nope = dp[i-1];
        long long x = i - l[i] - 1;
        long long dpp = (x >= 0) ? dp[x] : 0;
        long long mua = 1 + dpp;
        dp[i] = max(nope, mua);
    }
    cout << dp[n] << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    subtask1();
    return 0;
}