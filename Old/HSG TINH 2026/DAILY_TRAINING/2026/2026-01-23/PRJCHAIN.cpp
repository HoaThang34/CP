/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "PRJCHAIN"
#define int long long
int n;
vector<pair<int, int>> a;
bool cmp(pair<int, int> x, pair<int, int> y){
    bool ok1 = false;
    if (x.second >= x.first){
        ok1 = true;
    }
    bool ok2 = false;
    if (y.second >= y.first){
        ok2 = true;
    }
    if (ok1 != ok2) return ok1;
    else if (ok1) return x.first < y.first;
    else return x.second > y.second;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].second;
    }
    sort(a.begin() + 1, a.begin() + 1 + n, cmp);
    int k = 0, ans = 0;
    for (int i = 1; i <= n; i++){
        if (k < a[i].first){
            ans += a[i].first - k;
            k = a[i].first;
        }
        k = k - a[i].first + a[i].second;
    }
    cout << ans << endl;
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
