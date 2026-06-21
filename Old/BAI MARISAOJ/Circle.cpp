/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "circle"

void hoathang(){
    double r;
    cin >> r;
    const double pi = acos(-1.0);
    double c = 2 * pi * r;
    double a = pi * r * r;
    cout << fixed << setprecision(3) << c << " " << a << endl;
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