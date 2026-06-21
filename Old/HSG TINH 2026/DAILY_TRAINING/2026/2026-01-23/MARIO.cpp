/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "MARIO"
int n;
long long d;
vector<long long> a, x, y;
void sub1(){
    long long ans = 0, k = 0;
    for (int i = 1; i < n; i++){
        long long cur = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        k -= d*cur;
        if (k < ans){
            ans = k;
        }
        if (i + 1 < n) k+=a[i + 1];
    }
    cout << abs(ans) << endl;
}
void sub2(){
    long long ans = d*(abs(x[1] - x[n]) + abs(y[1] - y[n]));
    cout << ans << endl;
}
bool check(long long mid){
    vector<long long> f(n + 5, -1);
    f[1] = mid;
    for (int k = 1; k <= n; k++){
        bool ok = false;
        for (int u = 1; u <= n; u++){
            if (f[u] < 0) continue;
            for (int v = 1; v <= n; v++){
                if (u==v) continue;
                long long c = abs(x[u] - x[v]) + abs(y[u] - y[v]);
                long long dis = d*c;
                if (f[u] >= dis){
                    if (f[v]<f[u] - dis + a[v]){
                        f[v] = f[u] - dis + a[v];
                        ok = true;
                    }
                }
            }
        }
        if (!ok) break;
    }
    return f[n] >= 0;
}
void sub3(){
    long long l = 0, r = 1e18, ans = 1e18;
    while (l <= r){
        long long mid = (l + r)/2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> n >> d;
    a.resize(n + 5);
    x.resize(n + 5);
    y.resize(n + 5);
    bool ok1 = true, ok2 = true;
    for (int i = 2; i <= n - 1; i++){
        cin >> a[i];
        if (a[i] != 0) ok2 = false;
    }
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        if (x[i] <= x[i - 1]||y[i] != 0){
            ok1 = false;
        }
    }
//    sub1();
    if (ok1) sub1();
    else if (ok2) sub2();
    else sub3();
//    sub3();
//    sub2();

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
