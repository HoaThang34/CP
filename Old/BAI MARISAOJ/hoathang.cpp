/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int limits = 1e3+7;
#define endl '\n'
#define nap "hoathang"
int n,m;
int a[limits][limits]
void hoathang()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
    for (int i=1; i<=n; i++)
    {
        if (i%2 == 0)
        {
            int a = i;
            int b = j;
            while (a>0)
            {
                cout << a[a-1][b-1];
                a--;
                b--;
            }
        }
        for (int j = 1; j<=m; j++)
        {
            if (j%2==0)
            {
                int a = i,
            }
        }
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
