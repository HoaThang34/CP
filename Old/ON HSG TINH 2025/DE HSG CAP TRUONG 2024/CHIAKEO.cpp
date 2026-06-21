/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "CHIAKEO"
long long n, k;
vector <long long> a;
void hoathang()
{
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long s = n*(n + 1)/2;
    if (s % k != 0)
    {
        cout << -1 << endl;
        return;
    }
    long long du = s/k;
    if (n > du)
    {
        cout << -1 << endl;
        return;
    }
    vector <long long> ans (n + 5);
    set <pair<long long, long long>> st;
    for (int i = 1; i <= k; i++)
    {
        st.insert({0, i});
    }
    for (int i = n; i >= 1; i--)
    {
        pair <long long, long long> it = *st.begin();
        st.erase(st.begin());
        long long x = it.first, y = it.second;
        ans[i] = y;
        x += i;
        st.insert({x, y});
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
