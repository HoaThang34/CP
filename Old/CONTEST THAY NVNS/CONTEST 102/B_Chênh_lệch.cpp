/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// const long long N = 1e4 + 5;
#define nap ""

long long n, q;
vector <long long> a;
int u, v;

long long gcd(long long a, long long b){
    long long tmp;
    while (b > 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void hoathang(){
    cin >> n >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <long long> f (n + 5, 0);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        long long s = f[u - 1] + f[v];
        int l = u, r = v - 1;
        long long ans = 1e18;
        while (l <= r) {
            int mid = (l + r) / 2;
            long long val = 2 * f[mid] - s;
            ans = min(ans, abs(val));
            if (val < 0) l = mid + 1;
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}