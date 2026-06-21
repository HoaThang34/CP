/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n, k;
vector <long long> a;

void hoathang()
{
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
//    sort(a.begin() + 1, a.begin() + n + 1);
//    reverse(a.begin() + 1, a.begin() + n + 1);
    vector <long long> f(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + a[i];
    }
    int l = 1;
    long long ans = 0;
    for (int l = 1; l <= n; l++)
    {
        int it = lower_bound(f.begin() + l, f.begin() + 1 + n, f[l - 1] + k) - f.begin();
        ans += n - it + 1;
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
    hoathang();
    return 0;
}
