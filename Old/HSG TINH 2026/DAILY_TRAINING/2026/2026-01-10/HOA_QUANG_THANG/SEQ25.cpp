/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEQ25"
int n, q, k;
vector <int> a;
int rmin = 1e9, rmax = -1e9;
void sub1(){
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] >= k) cnt++;
        else if (a[i] < k){
            ans = max(ans, cnt);
            cnt = 0;
        }
        ans = max(ans, cnt);
//        cout << cnt << ' ';
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> n >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rmin = min(rmin, a[i]);
        rmax = max(rmax, a[i]);
    }
    while (q--){
        cin >> k;
        if (k <= rmin) cout << n << endl;
        else if (k > rmax) cout << 0 << endl;
        else sub1();
    }
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
