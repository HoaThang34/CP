/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CTREE"
int n, rmin = 1e9, rmax = -1e9;
vector <int> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rmax = max(rmax, a[i]);
        rmin = min (rmin, a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] == rmin) cnt++;
    }
    int ans = 0;
    if (rmax == rmin) ans = n;
    else ans = n - rmin;
    cout << rmin << ' ' << ans << endl;
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
