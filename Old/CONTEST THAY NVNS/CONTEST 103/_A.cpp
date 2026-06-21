/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<long long> b(7, 0);
    long long s = 0;
    int f, v;
    for(int i = 0; i < n1; ++i)
    {
        cin >> f >> v;
        b[f] += v;
        s += v;
    }
    for(int i = 0; i < n2; ++i)
    {
        cin >> f >> v;
        b[f] += v;
        s += v;
    }
    for(int i = 0; i < n3; ++i)
    {
        cin >> f >> v;
        b[f] += v;
        s += v;
    }
    long long res = -2e18;
    for (int d1 = 1; d1 <= 6; ++d1)
    {
        for (int d2 = 1; d2 <= 6; ++d2)
        {
            for (int d3 = 1; d3 <= 6; ++d3)
            {
                map<int, int> cnt;
                cnt[d1]++;
                cnt[d2]++;
                cnt[d3]++;
                long long p = 0;
                for (auto const& [key, val] : cnt)
                {
                    p += b[key] * (val + 1);
                }
                long long cur = p - s;
                if (cur > res)
                {
                    res = cur;
                }
            }
        }
    }
    cout << res << endl;
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
