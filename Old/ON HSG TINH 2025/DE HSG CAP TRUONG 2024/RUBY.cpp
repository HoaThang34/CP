/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "RUBY"
long long n;
vector <long long> a;
void hoathang()
{
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map <long long, long long> cnt;
    int l = 1;
    long long ans = -1e18;
    for (int r = 1; r <= n; r++)
    {
        if (cnt[a[r]] >= l)
        {
            l = cnt[a[r]] + 1;
        }
        cnt[a[r]] = r;
        ans = max(ans, (long long)r - l + 1);
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
