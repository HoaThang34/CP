/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "NANGLUC"
int n, k;
vector <int> a, f;
void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    f.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++){
        auto it = upper_bound(f.begin(), f.begin() + i, f[i] - k);
        if (it != f.begin()){
            int pos = distance(f.begin(), it) - 1;
            ans = max(ans, (f[i] - f[pos]) / (i - pos));
        }
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
