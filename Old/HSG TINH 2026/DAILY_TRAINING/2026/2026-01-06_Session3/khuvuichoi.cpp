/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "khuvuichoi"
int l, r;
void sub1(){
    int ans = 0;
    if (r - l > 4){
        ans += 24;
        ans += 3*(r - l - 4);
    }
    else ans += (r - l)*6;
    cout << ans << endl;
}
void sub2(){
    int ans = 0;
    if (r - l > 4){
        ans += 40;
        ans += 5*(r - l - 4);
    }
    else ans += (r - l)*10;
    cout << ans << endl;
}
void sub3(){
    int n = r - l;
    vector<int> a;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        int pos = l + i - 1;
        if (pos < 12) a[i] = 6;
        else a[i] = 10;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        if (i <= 4) ans += a[i];
        else ans += a[i] / 2;
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> l >> r;
    if (r <= 12) sub1();
    else if (l >= 12) sub2();
    else sub3();
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
