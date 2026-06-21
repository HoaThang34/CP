/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "BL02"

long long n, s, res = 0;
long long a[1000005], p[1000005], bit[1000005];
vector<long long> v;
void upd(int i, int val) {
    for (; i <= v.size(); i += i & -i) bit[i] += val;
}
long long get(int i) {
    long long s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}
void hoathang() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s;
    p[0] = 0;
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + (a[i] - s);
        v.push_back(p[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i <= n; i++) {
        int pos = lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1;
        res += get(pos);
        upd(pos, 1);
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")) {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
