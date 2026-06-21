/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "C"
int n;
vector <int> a, b;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    b.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    int m = 0;
    for (int i = 1; i <= n; i++){
        if (i == 1 || a[i] != a[i - 1]){
            b[++m] = a[i];
        }
    }
    int ans = 1, cur = 1;
    for (int i = 2; i <= m; i++){
        if (b[i] == b[i - 1] + 1){
            cur++;

        }
        else cur = 1;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
