/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DAYSO"
int n;
vector<int> a;
vector<long long> f;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    f.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    f[1] = a[1];
    for (int i = 1; i <= n; i++){
        f[i] = (long long)a[i]*i;
        cout << f[i] - f[i - 1] << ' ';
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
