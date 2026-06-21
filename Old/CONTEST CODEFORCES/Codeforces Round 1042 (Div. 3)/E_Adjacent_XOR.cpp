/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang(){
    long long n;
    cin >> n;
    vector<long long> a, b;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (a[n - 1] != b[n - 1]){
        cout << "NO" << endl;
        return;
    }
    map<long long, int> dem_a, dem_b;
    dem_a[a[0]]++;
    for (int i = 0; i < n - 1; ++i){
        dem_a[a[i] ^ a[i + 1]]++;
    }
    dem_b[b[0]]++;
    for (int i = 0; i < n - 1; ++i){
        dem_b[b[i] ^ b[i + 1]]++;
    }
    if (dem_a == dem_b){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}