/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "UNIQUESUB"

void hoathang(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    map<int, int> mp;
    int ans = 0, l = 0;

    for(int r = 0; r < n; ++r){
        if(mp.count(a[r])){
            l = max(l, mp[a[r]] + 1);
        }
        mp[a[r]] = r;
        ans = max(ans, r - l + 1);
    }

    cout << ans;
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
