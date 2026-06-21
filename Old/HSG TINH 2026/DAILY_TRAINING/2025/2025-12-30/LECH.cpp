/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e9 + 5;
#define endl '\n'
#define nap "LECH"
int n;
vector <int> a;
void hoathang(){
    cin >> n;
    int ans = NMAX;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    for (int i =1; i <= n - 1; i++){
        int dis = abs(a[i] - a[i + 1]);
        ans = min(ans, dis);
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
