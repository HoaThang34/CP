/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "STRING"

int n, a, b;
string x, y;
vector<long long> d1, d2;

vector<int> KMP(string s) {
    int m = s.length();
    vector<int> p(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

int GetOv(string A, string B) {
    string s = B + '#' + A;
    vector<int> p = KMP(s);
    int v = p.back();
    while (v >= B.length()) v = p[v - 1];
    return v;
}

long long Calc(string T, int ov) {
    long long sc = 0;
    if (x.length() <= T.length()) {
        string s = x + '#' + T;
        vector<int> p = KMP(s);
        for (int i = x.length() + 1; i < s.length(); i++) {
            if (p[i] == x.length() && (i - (x.length() + 1)) >= ov) sc += a;
        }
    }
    if (y.length() <= T.length()) {
        string s = y + '#' + T;
        vector<int> p = KMP(s);
        for (int i = y.length() + 1; i < s.length(); i++) {
            if (p[i] == y.length() && (i - (y.length() + 1)) >= ov) sc += b;
        }
    }
    return sc;
}

void hoathang(){
    if (!(cin >> n >> a >> b)) return;
    cin >> x >> y;

    int lx = x.size(), ly = y.size();

    int ov11 = GetOv(x, x);
    int ov12 = GetOv(x, y);
    int ov21 = GetOv(y, x);
    int ov22 = GetOv(y, y);

    long long g11 = Calc(x, ov11);
    long long g12 = Calc(y, ov12);
    long long g21 = Calc(x, ov21);
    long long g22 = Calc(y, ov22);

    long long init1 = Calc(x, 0);
    long long init2 = Calc(y, 0);

    d1.assign(n + 1, -1);
    d2.assign(n + 1, -1);

    if (lx <= n) d1[lx] = init1;
    if (ly <= n) d2[ly] = init2;

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        if (d1[i] != -1) {
            ans = max(ans, d1[i]);
            if (i + lx - ov11 <= n)
                d1[i + lx - ov11] = max(d1[i + lx - ov11], d1[i] + g11);
            if (i + ly - ov12 <= n)
                d2[i + ly - ov12] = max(d2[i + ly - ov12], d1[i] + g12);
        }
        if (d2[i] != -1) {
            ans = max(ans, d2[i]);
            if (i + lx - ov21 <= n)
                d1[i + lx - ov21] = max(d1[i + lx - ov21], d2[i] + g21);
            if (i + ly - ov22 <= n)
                d2[i + ly - ov22] = max(d2[i + ly - ov22], d2[i] + g22);
        }
    }
    cout << ans << endl;
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
