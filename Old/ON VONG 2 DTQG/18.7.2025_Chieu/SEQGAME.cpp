#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a, b;
#define task "SEQGAME"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    long long rmin = LLONG_MAX;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            rmin = min(rmin, abs(a[i] + b[j]));
        }
    }
    cout << rmin;
    return 0;
}