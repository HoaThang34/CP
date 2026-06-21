/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
long long g, c, l;
void hoathang(){
    cin >> g >> c >> l;
    vector <long long> a = {g, c, l};
    sort (a.begin(), a.end());
    if (a[2] - a[0] >= 10){
        cout << "check again" << endl;
    } else{
        cout << "final " << a[1] << endl;
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
