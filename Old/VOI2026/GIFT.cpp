/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "GIFT"

int n, q;
vector<pair<int, int>> a;

bool check(long m, long k, long t) {
    if (t == 0) return 1;
    long nd = t * k, cw = 0, cc = 0;
    for (auto p : a) {
        long tk = min((long)p.second, t);
        if (cc + tk > nd) tk = nd - cc;
        cw += tk * p.first;
        cc += tk;
        if (cw > m) return 0;
        if (cc == nd) return 1;
    }
    return (cc == nd && cw <= m);
}

void hoathang(){
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    sort(a.begin(), a.end());
    long sum = 0;
    for(auto p : a) sum += p.second;
    while (q--) {
        int loai; cin >> loai;
        if (loai == 1) {
            long m, k, t; cin >> m >> k >> t;
            if (t * k <= sum && check(m, k, t)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else{
            long m, k;
            cin >> m >> k;
            long l = 0, r = sum / k, res = 0;
            while(l <= r){
                long mid = (l + r) / 2;
                if(check(m, k, mid)){
                    res = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            cout << res << endl;
        }
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
