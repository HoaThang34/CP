/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap ""
int n, k;
vector<int> a;
vector<long long> f;
void hoathang(){
    cin >> n>> k;
    a.resize(n + 5);
    f.resize(n + 5);
    unordered_map<long long, int> cnt;
    cnt[0] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i] - k;
        if (cnt[f[i]] == 0) cnt[f[i]] = i;
        else ans = max(ans, (long long)i - cnt[f[i]]);
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
