/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
long long n;
void hoathang(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        long long kk = i*i;
        long long n1 = kk * (kk-1)/2;
        long long n2 = 4*(i-1)*(i-2);
        long long ans = n1 - n2;
        cout << ans << endl;
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
