#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = LLONG_MAX;
    sort(a.rbegin(), a.rend());
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            long long k = a[i] + a[j];
            // cerr << k << '\n';
            if (k % 2 == 0){
                cout << k;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}