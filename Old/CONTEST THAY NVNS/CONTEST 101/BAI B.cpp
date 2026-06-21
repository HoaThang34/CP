/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

void hoathang(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    int u = 1, v = 1e6, d = 1e9;

    for (int i = 0; i < n; ++i){
        int L = abs(a[i]);
        if (L > v) continue;
        int low = max(u, L);
        int high = min(v, L + d);

        if (low <= high && high - low < d){
            u = low;
            v = high;
            d = high - low;
        }
    }

    if (d == 1e9) cout << -1;
    else cout << u << " " << v;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();
    return 0;
}