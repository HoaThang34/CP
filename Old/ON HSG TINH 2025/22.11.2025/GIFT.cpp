/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "GIFT"
long long n;
void hoathang(){
    cin >> n;
    if (n <= 2) cout << 0 << endl;
    else cout << (n - 1) / 2 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;

    while (t--) hoathang();
    return 0;
}
