/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

void hoathang(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, n;
        cin >> a >> b >> n;

        if (n <= a / b) {
            cout << 1 << endl;
        } else {
            if (a == b) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
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