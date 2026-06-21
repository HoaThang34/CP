/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

int n;
long long u, vv;
vector<long long> w, val;
long long ans = 0;

void dfs(int i, long long sw, long long sv){
    if (sw > vv) return;
    if (i == n){
        if (u <= sw && sw <= vv) ans = max(ans, sv);
        return;
    }
    dfs(i + 1, sw, sv);
    dfs(i + 1, sw + w[i], sv + val[i]);
}

void hoathang(){
    cin >> n >> u >> vv;
    w.resize(n); val.resize(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> val[i];
    ans = 0;
    dfs(0, 0, 0);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    while (t--){
        hoathang();
    }
    return 0;
}
