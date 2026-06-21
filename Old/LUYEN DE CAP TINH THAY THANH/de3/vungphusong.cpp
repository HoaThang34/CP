/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" 

void hoathang(){
    int n;
    long long d;
    if (!(cin >> n >> d)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        while (a[r] - a[l] > d) {
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
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