/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "LAIXE"
long long n, m;
vector <pair<long long, long long>> a;
void subtask1()
{
    //n = 1;
    long long d1 = a[1].first, d2 = a[1].second;
    long long ans = d1 + abs(d1 - d2) + abs(d2 - m);
    cout << ans;
}
void subtask2()
{
    long long a1 = a[1].first, a2 = a[1].second;
    long long b1 = a[2].first, b2 = a[2].second;
    long long dis1 = a1 + abs(a1 - a2) + abs(a2 - b1) + abs(b1 - b2) + abs(b2 - m);
    long long dis2 = a1 + abs(a1 - b1) + abs(b1 - b2) + abs(b2 - a2) + abs(a2 - m);
    long long dis3 = a1 + abs(a1 - b1) + abs(b1 - a2) + abs(a2 - b2) + abs(b2 - m);
    long long dis4 = b1 + abs(b1 - b2) + abs(b2 - a1) + abs(a1 - a2) + abs(a2 - m);
    long long dis5 = b1 + abs(b1 - a1) + abs(a1 - a2) + abs(a2 - b2) + abs(b2 - m);
    long long dis6 = b1 + abs(b1 - a1) + abs(a1 - b2) + abs(b2 - a2) + abs(a2 - m);
    long long ans = min(dis1, min(dis2, min(dis3, min(dis4, min(dis5, dis6)))));
    cout << ans << endl;
}
void hoathang()
{
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    if (n == 1)
    {
        subtask1();
    }
    else if (n == 2)
    {
        subtask2();
    }
    else if (n == 3)
    {
        subtask2();
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
