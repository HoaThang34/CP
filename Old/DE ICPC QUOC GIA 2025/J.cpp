/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

void hoathang()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> g[i][j];
        }
    }
    for (long long m = 1; m < (1LL << n); ++m)
    {
        vector<int> s;
        for (int i = 0; i < n; ++i)
        {
            if ((m >> i) & 1)
            {
                s.push_back(i);
            }
        }
        int k = s.size();
        if (k == 0) continue;

        vector<pair<int, int>> cd;
        for (int j = 0; j < n; ++j)
        {
            int d = 0;
            for (int r : s)
            {
                if (g[r][j])
                {
                    d++;
                }
            }
            if (d > 0)
            {
                cd.push_back({d, j});
            }
        }
        sort(cd.rbegin(), cd.rend());
        unordered_set<int> t;
        for (int i = 0; i < min((int)cd.size(), k - 1); ++i)
        {
            t.insert(cd[i].second);
        }
        vector<pair<int, int>> p;
        for (int r : s)
        {
            for (int j = 0; j < n; ++j)
            {
                if (g[r][j] && t.find(j) == t.end())
                {
                    p.push_back({r, j});
                }
            }
        }
        if (p.size() <= 50)
        {
            cout << p.size() << endl;
            for (const auto& act : p)
            {
                cout << act.first << " " << act.second << endl;
            }
            return;
        }
    }
    cout << -1 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap ".inp", "r"))
    {
        freopen(nap ".inp", "r", stdin);
        freopen(nap ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
    {
        hoathang();
    }
    return 0;
}
