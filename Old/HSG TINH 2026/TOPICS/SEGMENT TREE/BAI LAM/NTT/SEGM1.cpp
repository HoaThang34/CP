#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> t;
vector<ll> a;
void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    t[id] = t[id << 1] + t[id << 1 | 1];
}
void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || r < pos)
        return;
    if (l == r)
    {
        t[id] = val;
        // a[l] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
long long get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return t[id];
    int mid = (l + r) / 2;
    return get(2 * id, l, mid, u, v) + get(2 * id + 1, mid + 1, r, u, v);
}
void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    t.resize(4 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    build(1, 1, n);
    int c, v, b;
    for (int i = 1; i <= q; i++)
    {
        cin >> c >> v >> b;
        if (c == 1)
        {
            update(1, 1, n, v, b);
        }
        else
        {
            cout << get(1, 1, n, v, b) << '\n';
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