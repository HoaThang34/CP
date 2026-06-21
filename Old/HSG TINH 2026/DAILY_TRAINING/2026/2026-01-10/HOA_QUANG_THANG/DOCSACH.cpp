/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DOCSACH"
int n;
vector <int> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long s = 0;
    int rmax = 0;
    for (int i = 1; i <= n; i++){
        s += a[i];
        rmax = max(rmax, a[i]);
    }
    long long ans = max(s, (long long)rmax + rmax);
    cout << ans << endl;
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
