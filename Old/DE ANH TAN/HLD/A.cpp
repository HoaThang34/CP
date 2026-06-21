/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

const int N = 200005;
int n, q;
int v[N];
vector<int> g[N];
int p[N], d[N], sz[N], h[N];
int top[N], pos[N], c;
int base[N];
int t[4 * N];

void dfs1(int u, int pr, int de)
{
    p[u] = pr;
    d[u] = de;
    sz[u] = 1;
    h[u] = 0;
    int mx = 0;
    for (int x : g[u])
    {
        if (x == pr) continue;
        dfs1(x, u, de + 1);
        sz[u] += sz[x];
        if (sz[x] > mx)
        {
            mx = sz[x];
            h[u] = x;
        }
    }
}

void dfs2(int u, int tp)
{
    top[u] = tp;
    pos[u] = ++c;
    base[c] = v[u];
    if (h[u])
    {
        dfs2(h[u], tp);
    }
    for (int x : g[u])
    {
        if (x == p[u] || x == h[u]) continue;
        dfs2(x, x);
    }
}

void build(int k, int l, int r)
{
    if (l == r)
    {
        t[k] = base[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * k, l, m);
    build(2 * k + 1, m + 1, r);
    t[k] = max(t[2 * k], t[2 * k + 1]);
}
void upd(int k, int l, int r, int i, int val)
{
    if (l == r)
    {
        t[k] = val;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m)
    {
        upd(2 * k, l, m, i, val);
    }
    else
    {
        upd(2 * k + 1, m + 1, r, i, val);
    }
    t[k] = max(t[2 * k], t[2 * k + 1]);
}
int get(int k, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return t[k];
    }
    int m = (l + r) / 2;
    return max(get(2 * k, l, m, u, v), get(2 * k + 1, m + 1, r, u, v));
}
int path(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (d[top[u]] < d[top[v]]) swap(u, v);
        res = max(res, get(1, 1, n, pos[top[u]], pos[u]));
        u = p[top[u]];
    }
    if (d[u] > d[v]) swap(u, v);
    res = max(res, get(1, 1, n, pos[u], pos[v]));
    return res;
}

void hoathang()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, vv;
        cin >> u >> vv;
        g[u].push_back(vv);
        g[vv].push_back(u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while (q--)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
        {
            int x, y;
            cin >> x >> y;
            upd(1, 1, n, pos[x], y);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << path(a, b) << ' ';
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
