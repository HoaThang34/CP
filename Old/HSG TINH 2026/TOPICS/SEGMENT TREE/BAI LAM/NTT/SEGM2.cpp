#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;
vector<ll> t;
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    t[id] = min(t[id * 2], t[id * 2 + 1]);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        t[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    t[id] = min(t[id * 2], t[id * 2 + 1]);
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (u > r || v < l)
    {
        return 1e18;
    }
    if (u <= l && r <= v)
    {
        return t[id];
    }
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    t.resize(n * 4 + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    build(1, 1, n);
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            update(1, 1, n, y, z);
        }
        else
        {
            cout << get(1, 1, n, y, z) << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}