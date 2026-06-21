/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "ga"
int n;
long long x;
vector<long long> a, t;
bool check(long long k){
    long long cnt = 0;
    for (int i = 1; i <= n; i++){
        if (k >= a[i]){
            cnt += (k - a[i]) / t[i] + 1;
        }
        if (cnt >= x){
            return true;
        }
    }
    return cnt >= x;
}
void hoathang(){
    cin >> n >> x;
    a.resize(n + 5);
    t.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> t[i];
    }
    long long l = 0;
    long long r = 1e18;
    long long ans = -1;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
