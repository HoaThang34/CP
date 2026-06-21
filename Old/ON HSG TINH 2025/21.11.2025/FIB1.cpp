/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "FIB1"
long long n, k;
vector <long long> a, b;
void hoathang(){
    int t;
    cin >> t;
    a.resize(t + 5);
    b.resize(t + 5);
    long long rmax = -1e18;
    for (int i = 1; i <= t; i++){
        cin >> a[i] >> b[i];
        rmax = max(rmax, a[i]);
    }
    vector <string> f(rmax + 5);
    f[0] = "a"; f[1] = "b";
    for (int i = 2; i <= rmax; i++){
        f[i] = f[i - 2] + f[i - 1];
    }
    for (int i = 1; i <= t; i++){
        string s = f[a[i]];
        cout << s[b[i] - 1] << endl;
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
