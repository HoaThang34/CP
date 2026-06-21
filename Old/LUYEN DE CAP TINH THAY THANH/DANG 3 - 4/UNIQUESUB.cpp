/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

void hoathang(){
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    map<int, int> pos;
    int ans = 0;
    int l = 0;
    for(int r=0; r<n; ++r){
        if(pos.count(a[r])){
            l = max(l, pos[a[r]] + 1);
        }
        pos[a[r]] = r;
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
