#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    vector<long long> ans;
    long long p10 = 10;
    for(int k = 1; k < 19; ++k){
        long long d = p10 + 1;
        if(d > n){
            break;
        }
        if(n % d == 0){
            ans.push_back(n / d);
        }
        if(p10 > LLONG_MAX / 10){
            break;
        }
        p10 *= 10;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size();
    for(long long x : ans){
        cout << " " << x;
    }
    cout << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}