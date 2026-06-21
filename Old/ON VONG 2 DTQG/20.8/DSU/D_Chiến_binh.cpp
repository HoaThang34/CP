#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1, 0);
    for (int i = 1; i <= m; i++){
        long long l, r, x;
        cin >> l >> r >> x;
        // cerr << l << r << x;
        for (int j = l; j <= r; j++){
            if (a[j] == 0 && j != x){
                a[j] = x;
            }
        }

    }
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    // for (long long x : a) cerr << x << ' ';
    return 0;
}