#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
long long x;
int a[MAXN];

const int bsz = 2 * MAXN + 2;
long long bit[bsz];

void update(int idx, int val) {
    for (; idx < bsz; idx += idx & -idx) {
        bit[idx] += val;
    }
}

long long query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen("dd.inp","r"))
    {
        freopen("dd.inp","r",stdin);
        freopen("dd.out","w",stdout);
    }
    cin >> n >> x;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    long long ans = 0;
    int o = n + 1;
    int res = 0;

    update(0 + o, 1);

    for (int j = 1; j <= n; j++) {
        if (a[j] >= x)
            res += 1;
        else
            res -= 1;
        ans += query(res + o);
        update(res + o, 1);
    }

    cout << ans << endl;

    return 0 ;
}