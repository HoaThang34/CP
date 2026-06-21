/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "demso"
long long a, b, c;
void sub1(){
    int d = 0;
    for (int i = a; i <= b; i++){
        if (i % c == 0) continue;
        d++;
    }
    cout << d<< endl;
}
void sub2(){
    long long dis = b - a + 1;
    long long d = (b/c) - ((a - 1)  /c);
    long long ans = dis - d;
    cout << ans << endl;
}
void hoathang(){
    cin >> a >> b >> c;
    if (a <= 1e6 && b <= 1e6 && c <= 1e6){
        sub1();
    }
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
