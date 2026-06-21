/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang(){
    long long n;
    cin >> n;
    vector<long long> a;
    a.resize(n + 1);
    vector<long long> b;
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    long long tg = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > b[i]){
            tg += a[i] - b[i];
        }
    }
    cout << tg + 1 << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}