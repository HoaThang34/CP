/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
int n;
int a[21];
long long s, t;
vector<string> res;
char p[21];

void ql(int k, long long sA, long long sB, long long sC) {
    if (sA > t || sB > t || sC > t) {
        return;
    }
    if (k > n) {
        if (sA == t && sB == t) {
            res.push_back(string(p + 1, n));
        }
        return;
    }

    p[k] = 'A';
    ql(k + 1, sA + a[k], sB, sC);

    p[k] = 'B';
    ql(k + 1, sA, sB + a[k], sC);

    p[k] = 'C';
    ql(k + 1, sA, sB, sC + a[k]);
}

void hoathang() {
    cin >> n;
    s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0) {
        cout << -1 << endl;
        return;
    }
    t = s / 3;
    ql(1, 0, 0, 0);
    if (res.empty()) {
        cout << -1 << endl;
    } else {
        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for (const string& str : res) {
            cout << str << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
