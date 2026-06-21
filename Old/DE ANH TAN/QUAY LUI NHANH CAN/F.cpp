/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

int n, w;
int a[25];
int dp[25][25];
void hoathang()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            dp[k][i] = w + 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= w)
        {
            dp[1][i] = a[i];
            res = 1;
        }
    }
    for (int k = 2; k <= n; k++)
    {
        bool ok = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (a[j] < a[i] && dp[k - 1][j] + a[i] <= w)
                {
                    dp[k][i] = min(dp[k][i], dp[k - 1][j] + a[i]);
                    ok = true;
                }
            }
        }
        if (ok)
        {
            res = k;
        }
        else
        {
            break;
        }
    }
    cout << res << endl;
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
