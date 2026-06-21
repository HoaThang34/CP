/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""

void hoathang(){
    int n, k;
    cin >> n >> k;
    vector<int> f(1002, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        f[a]++;
        f[b + 1]--;
    }

    int cur = 0;
    int ans = 0;
    for (int i = 1; i <= 1001; ++i) {
        cur += f[i];
        if (cur == k) {
            ans++;
        }
    }
    cout << ans << endl;
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