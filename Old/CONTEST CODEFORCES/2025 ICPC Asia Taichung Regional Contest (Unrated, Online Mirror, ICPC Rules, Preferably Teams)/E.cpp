/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

map<int, vector<string>> p;

void precompute() {
    string s;

    s = "12";
    sort(s.begin(), s.end());
    do {
        p[12].push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    s = "123";
    sort(s.begin(), s.end());
    do {
        p[123].push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    s = "1234";
    sort(s.begin(), s.end());
    do {
        p[1234].push_back(s);
    } while (next_permutation(s.begin(), s.end()));
}

void hoathang(){
    int n, j, k;
    cin >> n >> j >> k;

    string s1 = p[n][j - 1];
    string s2 = p[n][k - 1];

    int a = 0;
    int b = 0;
    int len = s1.length();

    vector<int> f1(10, 0);
    vector<int> f2(10, 0);

    for (int i = 0; i < len; ++i) {
        if (s1[i] == s2[i]) {
            a++;
        } else {
            f1[s1[i] - '0']++;
            f2[s2[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; ++i) {
        b += min(f1[i], f2[i]);
    }

    cout << a << "A" << b << "B" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    precompute();

    int t;
    cin >> t;
    while(t--) {
        hoathang();
    }

    return 0;
}
