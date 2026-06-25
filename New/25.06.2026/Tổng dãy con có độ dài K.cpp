/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap ""
#define endl '\n'
#define int long long
int n, k;
vector<int> a;

void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1, r = k;
    int s = 0;
    for (int i = 1; i <= r; i++){
        s += a[i];
    }
    int ans = s;
    while (r <= n){
        r++;
        s += a[r];
        s -= a[l];
        l++;
        ans = max(ans, s);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
