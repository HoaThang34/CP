/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SQUERY"
int n, q, l ,r, d;
vector<int> a;
void sub1(){
    int cnt = 0;
    for (int i = l; i <= r; i++){
        if (d % a[i] == 0 || a[i] % d == 0){
            cnt++;
        }
    }
    cout << cnt << ' ';
}
void hoathang(){
    cin >> n >> q;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while (q--){
        cin >> l >> r >> d;
        sub1();
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
