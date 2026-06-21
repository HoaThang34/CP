/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

void hoathang(){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    map<long long, int> cnt;
    cnt[0] = 1;
    long long current_xor = 0;
    long long ans = 0;

    for(int x : a){
        current_xor ^= x;
        if (cnt.count(current_xor ^ k)){
            ans += cnt[current_xor ^ k];
        }
        cnt[current_xor]++;
    }
    cout << ans;
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
