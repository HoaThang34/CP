/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

void hoathang()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        p[i + 1] = p[i] + a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, p[i]);
    }
    vector<long long> f(n + 1);
    f[0] = p[0];
    for (int i = 1; i <= n; ++i)
    {
        f[i] = max(f[i - 1], p[i]);
    }
    vector<long long> mxs(n + 2);
    mxs[n + 1] = -2e18;
    mxs[n] = p[n];
    for (int i = n - 1; i >= 0; --i)
    {
        mxs[i] = max(mxs[i + 1], p[i]);
    }
    for (int m = 0; m < n; ++m)
    {
        ans = max(ans, f[m] - p[m] + mxs[m + 1]);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r"))
    {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while(t--) hoathang();
    return 0;
}
