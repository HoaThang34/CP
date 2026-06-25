/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap ""
#define endl '\n'
#define int long long
int n, x;
vector<int> a;

void hoathang(){
    cin >> n >> x;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1;
    int ans = 0;
    int s = 0;
    for (int r = 1; r <= n; r++){
        s += a[r];
        while (s > x){
            s -= a[l];
            l++;
        }
        ans = max (ans, r - l + 1);
    }
    cout << ans;
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
