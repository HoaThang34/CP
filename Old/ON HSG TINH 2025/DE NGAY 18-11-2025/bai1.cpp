/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai1"
long long n;
long long demuoc(long long n){
    long long d = 0;
    for (int i = 1; i <= n; i++){
        if (n % i == 0) d++;
    }
    return d;
}
void sub1(){
    long long ans = demuoc(n);
//    cout << n << endl;
    if (ans % 2 == 0) cout << "CHAN" << endl;
    else cout << "LE" << endl;
}
bool chinhphuong(long long n){
    long long x = sqrt(n);
    long long ans = x*x;
    if (ans == n) return true;
    return false;
}
void sub2(){
    bool ok  = chinhphuong(n);
    if (ok)
        cout << "LE" << endl;
    else cout << "CHAN" << endl;
}
void hoathang(){
    cin >> n;
//    sub1();
    sub2();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--) hoathang();
    return 0;
}
