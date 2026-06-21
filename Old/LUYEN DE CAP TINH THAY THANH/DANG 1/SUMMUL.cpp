/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SUMMUL"
long long n, k;
void sub1(){
    long long s = 0;
    for (long long i = 1; i <= n; i++){
        if (i % k == 0) s += i;
    }
    cout << s << endl;
}
void sub2(){
    long long m = n/k;
    long long ans = k*(m* (m + 1))/2;
    cout << ans << endl;
}
void hoathang(){
    cin >> n >> k;
//    sub1();
    sub2();
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
