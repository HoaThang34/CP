/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SQRNUM"
long long l, r;
bool check(long long n){
    long long du = sqrt(n);
    return (du*du == n);
}
void sub1(){
    long long d = 0;
    for (long long i = l; i <= r; i++){
        if (check(i)) d++;
    }
    cout << d<< endl;
}
void sub2(){
    long long n1 = ceil(sqrt(l));
    long long n2 = floor(sqrt(r));
    cout << n2 - n1 + 1 << endl;
}
void hoathang(){
    cin >> l >> r;
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
