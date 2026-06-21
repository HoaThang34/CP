/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n, q;
vector <long long> a;
vector <long long> f;
void hoathang(){
    cin >> n >> q;
    a.resize(n + 1);
    f.resize(n + 5, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    while (q--){
        long long l, r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl;
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
