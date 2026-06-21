/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai1"
long long n;
void hoathang(){
    cin >> n;
    long long k = sqrt(n);
    k = k*k;
    if (k == n){
        cout << "LE" << endl;
    }
    else cout << "CHAN" << endl;
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
