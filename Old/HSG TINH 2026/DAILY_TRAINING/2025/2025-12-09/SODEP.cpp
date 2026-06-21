/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define nap "SODEP"
int n, m;
vector <int> a;
long long gcd(long long a, long long b){
    while(b > 0){
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
long long lcm(long long a, long long b){
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    if (b == 1) return a;
    long long c = gcd(a, b);
    long long va = a / c;
    if (b > 0 && 1e18 / b < va) {
        return 1e18;
    }
    return va * b;
}

void hoathang(){
    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i < (1 << n); i++){
        long long k = 1;
        int cnt = __builtin_popcount(i);
        bool ok = true;
        for (int j = 0; j < n; j++){
            if ((i >> j) & 1){
                k = lcm(k , a[j + 1]);
                if(k == 0 || k > m){
                    ok = false;
                    break;
                }
            }
        }
        if (ok){
            if (cnt % 2 == 1) ans += m / k;
            else ans -= m / k;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
