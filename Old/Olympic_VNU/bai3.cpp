/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "bai3"
long long l, r;

void hoathang(){
    cin >> l >> r;
    vector <long long> a;
    for (long long i = l; i <= r; i++){
        long long x = i, d = 0;
        while (x){
            d++;
            x/=10;
        }
        long long sq = i*i, p = 1;
        for (int j = 0; j < d; j++){
            p*=10;
        }
        long long right  = sq % p, left = sq/p;
        if (left + right == i){
            a.push_back(i);
        }
    }
    cout << a.size() << endl;
    for (long long x : a) cout << x << ' ';
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
