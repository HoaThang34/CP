/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU1"
long long n, k;
unordered_map<long long, long long> cnt;
void sub1(){
    long long d = 0;
    for (long long i = 1; i <= n;  i++){
        if (cnt[k - i] > 0){
            d += cnt[k - i];
        }
        cnt[i]++;
    }
    cout << d<< endl;
}
void sub2(){
    long long l, r;
    if (k - n > 0){
        l = k - n;
    }
    else l = 1;
    r = (k - 1) /2;
    if (l <= r){
        cout << r-l+1 << endl;
    }
    else cout << 0 << endl;
}
void hoathang(){
    cin >> n>>  k;
//    sub1();
//    sub2();
    if(n <= 1e6 && k <= 1e6) sub1();
    else sub2();
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
