/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" // Neu bai yeu cau nhap xuat bang file thi thay ten de bai vao day.

void hoathang(){
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> v;
    for (int x : a) {
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end()) {
            v.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << v.size() << endl;
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