/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "VUOTKHO" 

void hoathang(){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Buoc 1: Sap xep tang dan
    sort(a.begin(), a.end());

    // Buoc 2: Hai con tro
    long long dem = 0;
    int l = 0, r = n - 1;
    while(l < r){
        // Luu y ep kieu long long cho tong de tranh tran so (overflow)
        if( (long long)a[l] + a[r] >= k ){
            // Neu a[r] + a[l] du lon, thi a[r] + (bat ky ai tu l+1 den r-1) cung du lon
            dem += (r - l);
            r--; // Xet xong a[r], giam r
        } else {
            // Neu a[l] + a[r] khong du, thi a[l] qua nho
            l++; // Bo qua a[l], tang l
        }
    }
    cout << dem;
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