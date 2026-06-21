/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n;
const long long MOD = 1e9 + 7;
void hoathang()
{
    cin >> n;
    if (n == 1) cout << 3 << endl;
    else
    {
        long long a = 2, b = 1, tmp;
        for (int i = 2; i <= n; i++)
        {
            tmp = a;
            a = (2 * (a + b)) % MOD;
            b = tmp;
        }
        long long ans = a + b;
        cout << ans % MOD << endl;
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
