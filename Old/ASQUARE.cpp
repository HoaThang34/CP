/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "ASQUARE"
long long n, rmax1 = -1e18, rmax2 = -1e18, rmin1 = 1e18, rmin2 = 1e18;
void hoathang(){
    cin >> n;
    while (n--){
        long long x, y;
        cin >> x >> y;
        rmax1 = max(rmax1, x);
        rmax2 = max(rmax2, y);
        rmin1 = min(rmin1, x);
        rmin2 = min(rmin2, y);
    }
    long long x = rmax1 - rmin1;
    long long y = rmax2 - rmin2;
    long long ans = max(x, y);
    ans*=ans;
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