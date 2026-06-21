#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long a, b;
    cin >> n >> a >> b;
    
    if (n == 1) {
        long long x, y, r;
        cin >> x >> y >> r;
        long long dx = a - x;
        long long dy = b - y;
        double d = sqrt(dx * dx + dy * dy);
        if (d <= r) {
            cout << 0 << '\n';
        } else {
            long long l = (long long)(d - r - 1e-9);
            cout << l << '\n';
        }
    }
    else {
        long long ans = 1e18;
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            long long x, y, r;
            cin >> x >> y >> r;
            long long dx = a - x;
            long long dy = b - y;
            double d = sqrt(dx * dx + dy * dy);
            if (d <= r) {
                ok = 1;
            } else {
                long long l = (long long)(d - r - 1e9);
                ans = min(ans, l);
            }
        }
        if (ok) {
            cout << 0 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    
    return 0;
}