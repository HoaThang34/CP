/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "fixsub"

long long n, k, cur = 0, ans = -2e18;
vector<long long> a;

void hoathang(){
    if (!(cin >> n >> k)) return;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++){
        cur += a[i];
    }
    ans = cur;
    for (int i = k + 1; i <= n; i++){
        cur = cur - a[i - k] + a[i];
        ans = max(ans, cur);
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