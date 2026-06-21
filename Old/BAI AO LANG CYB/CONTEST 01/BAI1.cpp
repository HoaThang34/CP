/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n;
vector <long long> a;
long long gcd(long long a, long long b)
{
    long long tmp;
    while (b > 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void hoathang()
{
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long g = a[1];
    for (int i = 2; i <= n; i++)
    {
        long long x = a[i];
        g = gcd(g, a[i]);
        if (g == 1)
        {
            cout << -1 << endl;
            return;
        }

    }
    for (int i = 2; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            cout << i << endl;
            return;
        }
    }
    cout << g << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r"))
    {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
