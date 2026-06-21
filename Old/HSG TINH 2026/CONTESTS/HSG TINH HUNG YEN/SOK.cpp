/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SOK"
int n, t;
vector <long long> a;
void hoathang(){
    cin >> n >> t;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    while (t--){
        long long x;
        cin >> x;
        long long l = 1, r = 1e18, ans;
        while (l <= r){
            long long mid = (l + r)/2;
            long long it = upper_bound(a.begin(), a.begin() + n + 1, mid) - a.begin() - 1;
            long long pos = mid - it;
            if (pos >= x){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << endl;
    }
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
