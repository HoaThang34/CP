/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n, q;
map <long long, long long> cnt;


void hoathang(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        cnt[x]++;
    }    
    cin >> q;
    while (q--){
        long long x;
        cin >> x;
        cout << cnt[x] << endl;
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