#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    long long ans = 0;
    long long p3 = 1;
    long long x = 0;
    while(n > 0){
        long long digit = n % 3;
        if(digit > 0){
            long long d = 0;
            if(x == 0){
                d = 3;
            }else{
                d = 3 * p3 + x * (p3 / 3);
            }
            ans += digit * d;
        }
        n /= 3;
        if(n > 0 && p3 > LLONG_MAX / 3){
            break;
        }
        p3 *= 3;
        x++;
    }
    cout << ans << endl;
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