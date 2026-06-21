/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    bool ok = false;
    for (int i = 0; i < n - 1; ++i)
    {
        bool gr = (s[i] == '>' || s[i] == '*');
        bool gl = (s[i+1] == '<' || s[i+1] == '*');
        if (gr && gl)
        {
            ok = true;
            break;
        }
    }
    if (ok)
    {
        cout << -1 << endl;
        return;
    }
    int l = 0;
    while (l < n && s[l] == '<')
    {
        l++;
    }
    int r = 0;
    while (r < n && s[n - 1 - r] == '>')
    {
        r++;
    }
    int mid = n - l - r;
    if (mid == 0)
    {
        cout << max(l, r) << endl;
    }
    else
    {
        cout << max(l + mid, r + mid) << endl;
    }
}

void hoathang()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
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
