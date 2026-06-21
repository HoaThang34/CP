/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

long long MOD = 998244353;

void hoathang()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 1;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[j] + 1)
        {
            j++;
        }
        int k = j - i + 1;
        if (k % 2 != 0)
        {
            long long res = (k + 1) / 2;
            ans = (ans * res) % MOD;
        }
        i = j + 1;
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
    while(t--)
    {
        hoathang();
    }
    return 0;
}
