/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

bitset<100005> f;

void hoathang(){
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }

    f[0] = 1;
    for (int v : a) {
        f |= (f << v);
    }

    int k = s / 2;
    while (k >= 0 && !f[k]) {
        k--;
    }

    cout << abs(s - 2 * k) << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}