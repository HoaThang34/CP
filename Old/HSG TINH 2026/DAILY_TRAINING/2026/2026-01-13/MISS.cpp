/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "MISS"
#define int long long
int n, q, x;
vector <long long> a, f;
vector<int> cnt(1e6 + 5, 0);
void sub1(){
    long long st = 0;
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
        long long len = a[i] - st - 1;
        if (x <= len) {
            cout << st + x << endl;
            ok = 1;
            break;
        }
        x -= len;
        st = a[i];
    }
    if (!ok) {
        cout << st + x << endl;
    }
}
void sub2(){
    long long ans = 0;
    if (x > f[n]) ans = x - f[n] + a[n];
    else{
        int l = 1, r = n, res = n;
        while (l <= r){
            int mid = (l + r)/2;
            if (f[mid] >= x){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ans = x - f[res - 1] + a[res - 1];
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> n >> q;
    a.resize(n + 5);
    f.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = a[i] - i;
        if (a[i] <= 1e6){
            cnt[a[i]]++;
        }
    }
    while (q--){
        cin >>x ;
//        if (n <= 2000 && q <= 2000){
//            sub1();
//        }
//        else sub2();
//        sub1();
        sub2();
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
