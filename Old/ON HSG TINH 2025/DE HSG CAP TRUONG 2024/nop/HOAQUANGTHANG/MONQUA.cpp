/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "MONQUA"
long long n;
void hoathang()
{
    cin >> n;
    if (n <= 3)
    {
        cout << 1 << endl;
        return;
    }
    long long ans = 2;
    while (ans * 2 <= n)
    {
        ans *= 2;
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
