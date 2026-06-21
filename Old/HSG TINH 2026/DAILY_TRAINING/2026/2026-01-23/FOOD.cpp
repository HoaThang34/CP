/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "FOOD"
long long n, k;
vector<int> a;
void sub1(){
    long long s = 0;
    for (int i = 1; i <= n; i++){
        s += (a[i] + a[i]);
    }
    cout << s << endl;
}
void sub2(){
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        int rmin = 1e9 + 5;
        int rmax = max(1LL, i - k + 1);
        for (int j = rmax; j <= i; j++){
            rmin = min(rmin, a[j]);
        }
        ans += rmin + rmin;
//        cout << rmin << endl;
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (k == 1){
        sub1();
    }
    else sub2();
//    sub2();
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
