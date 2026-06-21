/** 
 * Author: Nguyen Duc Minh CYB (2K10)
 * Created: 2025-10-26 09:40:33
 */
#include <bits/stdc++.h>
using namespace std;

#define sol ""
#define endl '\n'
#define ll long long

void fre()
{
    if(!fopen(sol".inp", "r"))
        return;
    freopen(sol".inp", "r", stdin);
    freopen(sol".out", "w", stdout);
}

ll phi(ll n)
{
    ll ans = n;
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            ans -= ans / p;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

ll modpow(ll a, ll b, ll c)
{
    ll res = 1;
    a %= c;
    while(b > 0)
    {
        if(b & 1) res = res * a % c;
        a = a * a % c;
        b /= 2;
    }
    return res;
}

ll modmul(ll a, ll b, ll p)
{
    return ((a % p) * (b % p)) % p;
}

void solve()
{
    ll n, m, k, p;
    cin >> n >> k >> m >> p;
    ll tmp = modpow(2, phi(p) - 1, p);
    ll ans = modmul(n, m, p) - modmul(k - 1, (modmul(m, m - 1, p), tmp, p), p);
    cout << ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fre();
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}
//Toi Yeu Xuan