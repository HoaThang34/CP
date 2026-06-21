/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" 

void hoathang(){
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    long long mi = 2e18; 
    for (int i = 0; i <= n - k; i++) {
        long long diff = a[i + k - 1] - a[i];
        if (diff < mi) mi = diff;
    }
    cout << mi << endl;
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