#include <bits/stdc++.h>
using namespace std;
long long n, k;
#define task "LUCKY"
long long gcd(long long a, long long b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}
long long lcm(long long a, long long b, long long lim){
    if (a == 0 || b == 0) return 0;
    if (a > lim || b > lim) return lim + 1;
    long long g = gcd(a, b);
    if (a / g > lim / b) return lim + 1;
    return (a / g) * b;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    vector<long long> v;
    for(long long i = 2; i <= k; i++){
        v.push_back(i);
    }
    long long m = v.size();
    long long d1 = 0;
    for(long long i = 1; i < (1 << m); i++){
        long long lcmm = 1;
        int bt = 0;
        for(int j = 0; j < m; j++){
            if((i >> j) & 1){
                bt++;
                lcmm = lcm(lcmm, v[j], n);
                if(lcmm > n) break;
            }
        }
        if(lcmm > n) continue;
        long long d = n / lcmm;
        if(bt % 2 != 0){
            d1 += d;
        } else {
            d1 -= d;
        }
    }
    long long ans = n - d1;
    cout << ans;
    return 0;
}