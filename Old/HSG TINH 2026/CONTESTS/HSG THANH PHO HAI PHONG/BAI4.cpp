/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BAI4"
int n, m;
vector <int> a;
bool check(long long d){
    int pos = 1, ok = 0;
    while(pos <= n){
        ok++;
        if (ok > m) return false;
        int dis = upper_bound(a.begin() + 1, a.begin() + 1 + n, a[pos] + d) - a.begin() - 1;
        pos = upper_bound(a.begin() + 1, a.begin() + 1 + n, a[dis] + d) - a.begin();
    }
    return true;
}
void hoathang(){
    cin >> n>> m;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long l = 0, r = 1e18, ans = 1e18;
    while (l <= r){
        long long mid = (l + r) / 2;
        if (check(mid)){
            ans = mid;
            r = mid  - 1;
        }
        else l = mid + 1;
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
