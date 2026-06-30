/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
// note: max - min <= k
#define nap ""
#define endl '\n'
#define int long long
int n, k;
vector<int> a;
bool xuli(vector<int> a, int l, int r, int k){
    int rmax = LLONG_MIN;
    int rmin = LLONG_MAX;
    for (int i = l; i <= r; i++){
        rmin = min(rmin, a[i]);
        rmax = max(rmax, a[i]);
    }
    if (rmax - rmin <= k) return true;
    else return false;
}
void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1;
    int d = 0;
    for (int r = 1; r <= n; r++){
        while (!xuli(a, l, r, k)){
            l++;
        }
        d += r - l + 1;
    }
    cout << d <<endl;
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
