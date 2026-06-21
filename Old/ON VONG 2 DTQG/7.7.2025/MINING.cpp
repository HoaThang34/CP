#include <bits/stdc++.h>
using namespace std;
long long n, s;
vector <long long> a;

#define task "MINING"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> s;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long k = (s + n - 1) / n;
    cout << a[1] - k;
    return 0;
}