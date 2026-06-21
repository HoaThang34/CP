/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "maxprod"

long long n, ans, mx, mn;
vector<long long> a;

void hoathang(){
    if (!(cin >> n)) return;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    mx = a[1];
    mn = a[1];
    ans = a[1];
    for (int i = 2; i <= n; i++){
        if (a[i] < 0) swap(mx, mn);
        mx = max(a[i], mx * a[i]);
        mn = min(a[i], mn * a[i]);
        ans = max(ans, mx);
    }
    cout << ans;
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