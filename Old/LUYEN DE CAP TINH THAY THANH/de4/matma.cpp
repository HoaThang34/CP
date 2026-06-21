/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

bool p[1000005];

void sieve() {
    fill(p, p + 1000005, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i * i <= 1000000; i++) {
        if (p[i]) {
            for (int j = i * i; j <= 1000000; j += i) p[j] = 0;
        }
    }
}

int sd(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void hoathang() {
    sieve();
    int a, b;
    if (!(cin >> a >> b)) return;
    int res = 0;
    for (int i = a; i <= b; i++) {
        if (p[i] && p[sd(i)]) res++;
    }
    cout << res << endl;
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