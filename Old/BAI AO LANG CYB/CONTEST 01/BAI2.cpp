/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n;
void hoathang()
{
    cin >> n;
    cout << n << ' ';
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            cout << n << ' ';
        }
        else
        {
            n = (n*3) + 1;
            cout << n << ' ';
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
