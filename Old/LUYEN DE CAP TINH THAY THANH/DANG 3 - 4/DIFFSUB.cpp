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
    cin >> n>> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    multiset<int> ms;
    int l = 0;
    int ans = 0;
    
    for(int r=0; r<n; ++r){
        ms.insert(a[r]);
        while (!ms.empty() && (*ms.rbegin() - *ms.begin() > k)) {
            ms.erase(ms.find(a[l]));
            l++;
        }
        ans = max(ans, r - l + 1);
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
