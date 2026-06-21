/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "EVEXSLAP"
int n, rmin = 1e9, rmax = -1e9;
void hoathang(){
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        rmax = max(rmax, x);
        rmin = min(rmin, x);
    }
    cout << rmax << ' ' << rmin << endl;
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
