/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

long long t[100005], r[100005], f[100005];

void hoathang(){
    int n;
    if (!(cin >> n)) return;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i < n; ++i) cin >> r[i];

    f[0] = 0;
    f[1] = t[1];
    for (int i = 2; i <= n; ++i) {
        f[i] = min(f[i - 1] + t[i], f[i - 2] + r[i - 1]);
    }
    
    cout << f[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}