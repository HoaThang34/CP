/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n, q;
vector <long long> a;

void hoathang(){
    cin >> n >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    map <long long, vector <long long>> cnt;
    for (int i = 1; i <= n; i++){
        long long x = a[i];
        cnt[x].push_back(i);
    }
    while (q--){
        int l, r;
        long long x;
        cin >> l >> r >> x;
        vector <long long> d = cnt[x];
        long long it1 = lower_bound(d.begin(), d.end(), l) - d.begin();
        long long it2 = upper_bound(d.begin(), d.end(), r) - d.begin();
        cout << it2 - it1 << endl;
    }
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
