/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n, x;
vector <long long> a;
void hoathang()
{
    cin >> n >> x;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector <bool> ok(n + 5, false);
    sort(a.begin() + 1, a.begin() + 1 + n);
    long long d = 0;
    int l = 1, r = n;
    while (l <= r)
    {
        d++;
//        cerr << a[l] + a[r] << endl;
        if (l < r && a[l] + a[r] <= x)
        {
            l++;
            r--;
        }
        else r--;
    }
    cout << d << endl;
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
