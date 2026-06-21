/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "TROCHOI"
int m, n;
vector <int> a;
void sub1(){
    sort(a.begin() + 1, a.begin() + 1 + n*m);
    for (int i = 1; i <= m*n; i++)
        cout << a[i] << ' ';
}
void sub2(){
    sort(a.begin() + 1, a.begin() + 1 + m*n);
    int d = 1;
    for (int i = 1; i <= m; i++){
        vector <int> ans;
        for (int j = 1; j <= n; j++){
            ans.push_back(a[d]);
            d++;
        }
        if (i % 2 == 0) reverse(ans.begin(), ans.end());
        for (int x : ans) cout << x << ' ';
        cout << endl;
    }
}
void hoathang(){
    cin >> m >> n;
    a.resize(n*m + 5);
    for (int i = 1; i <= m*n; i++)
        cin >> a[i];

    if (m == 1) sub1();
    else sub2();
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
