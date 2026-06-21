/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "EXPFUEL"
int n, m, c, x;
vector <int> a, b;
vector<int> l;
vector <int> r;
void sub1(){
    long long ans = 1e18;
    for (int i = 1; i <= n; i++){
        ans = min(ans, (long long)b[i] + abs(a[i] - x) * c);
    }
    cout << ans << endl;
}
void xuli(){
    l.resize(n + 5);
    r.resize(n + 5);
    vector <pair<int, int>> p(n + 5);
    for (int i  = 1; i <= n; i++){
        p[i].first = a[i];
        p[i].second = b[i];
    }
    sort(p.begin() + 1, p.begin() + 1 + n);
    for (int i = 1; i <= n; i++){
        a[i] = p[i].first;
        b[i] = p[i].second;
    }
    l[0] = 1e9;
    for (int i = 1; i <= n; i++){
        l[i] = min(l[i - 1], b[i] - a[i] * c);
    }
    r[n + 1] = 1e9;
    for (int i = n; i >= 1; i--){
        r[i] = min(r[i + 1], b[i] + a[i] * c);
    }
}
void sub2(){
    int k = upper_bound(a.begin() + 1, a.begin() + n + 1, x) - (a.begin() + 1);
    int ans = 1e9;
    if (k >= 1){
        ans = min(ans, l[k] + x * c);
    }
    if (k < n){
        ans = min(ans, r[k + 1] - x * c);
    }
    cout << ans << endl;
}
void hoathang(){
    cin  >> n >> m  >> c;
    a.resize(n + 5);
    b.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    if (m > 1000){
        xuli();
    }
//    xuli();
    while (m--){
        cin >> x;
        if (m > 1000){
            sub2();
        }
        else sub1();
//        sub2();
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
