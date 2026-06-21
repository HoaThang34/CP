/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "quantrong"
int n;
vector <int> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <int> cnt(1005, 0);
    vector <long long> f(n + 5, 0);
    long long ans = -1;
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
        ans = max(ans, (long long)a[i]);
    }
    for (int i = 1; i <= n; i++){
        if (cnt[a[i]] != 0){
            long long s = f[i] - f[cnt[a[i]] - 1];
            ans = max(ans, s);
        }
        else cnt[a[i]] = i;
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
