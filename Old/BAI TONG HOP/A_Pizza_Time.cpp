/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

vector<long long> a;

void hoathang(){
    int t;
    cin >> t;

    a.resize(t);

    for (int i = 0; i < t; i++) cin >> a[i];

    for (int i = 0; i < t; i++){
        long long n = a[i];
        cout << (n - 1) / 2 << endl;
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
