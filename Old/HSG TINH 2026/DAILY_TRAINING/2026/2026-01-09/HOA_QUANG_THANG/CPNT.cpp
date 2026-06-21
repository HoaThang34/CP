/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "CPNT"

int t;
vector<long long> pre1, v;
vector<int> pre2, ok;

bool nt(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

long long sang2(long long n) {
    long long res = 1;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long p = 1, s = 1;
            while (n % i == 0) {
                p *= i;
                s += p;
                n /= i;
            }
            res *= s;
        }
    }
    if (n > 1) res *= (1 + n);
    return res;
}

void hoathang() {
    pre1.resize(1000005);
    pre2.resize(1000005);
    v.resize(1000005);
    ok.resize(1000005);
    for (long long i = 1; i * i <= 1000000; i++) {
        long long s = i * i;
        v[s] = s;
        if (nt(sang2(s))) ok[s] = 1;
    }
    for (int i = 1; i <= 1000000; i++) {
        pre1[i] = pre1[i - 1] + v[i];
        pre2[i] = pre2[i - 1] + ok[i];
    }
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pre1[b] - pre1[a - 1] << " " << pre2[b] - pre2[a - 1] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")) {
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
