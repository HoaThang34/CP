/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "TONGCHUSO"
long long n;
void sub1(){
    long long s = 0;
    while (n){
        s += n % 10;
        n/=10;
    }
    cout << s << endl;
}
void hoathang(){
    cin >> n;
    sub1();
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
