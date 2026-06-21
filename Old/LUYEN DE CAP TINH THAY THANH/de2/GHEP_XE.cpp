/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang(){
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, res = 0;
    while (i <= j) {
        if (i < j && a[i] + a[j] <= k) {
            i++;
            j--;
        } else {
            j--;
        }
        res++;
    }
    cout << res;
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