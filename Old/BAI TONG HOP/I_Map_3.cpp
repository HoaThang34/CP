/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n, q;
map <long long, vector <long long>> cnt;


void hoathang(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        cnt[x].push_back(i);
    }
    cin >> q;
    while (q--){
        int l, r;
        long long x;
        cin >> l >> r >> x;
        vector <long long> ans = cnt[x];
        int left = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
        int right = upper_bound(ans.begin(), ans.end(), r) - ans.begin();
        cout << right - left << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}