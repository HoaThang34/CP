#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> x, y;
void nhap()
{
    cin >> n;
    x.resize(n + 1);
    y.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

}
void subtask1()
{
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << x[(n + 1) /2] << ' ' << y[(n + 1) /2];
}
#define nap "dt"
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r"))
    {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    nhap();
    subtask1();
    return 0;
}
