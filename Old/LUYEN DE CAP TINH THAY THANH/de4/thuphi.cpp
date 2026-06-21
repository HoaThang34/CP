/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" // Neu bai yeu cau nhap xuat bang file thi thay ten de bai vao day.

void hoathang(){
    int n;
    long long s;
    if (!(cin >> n >> s)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long sum = 0;
    int ans = 0, l = 0;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum > s && l <= r) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}