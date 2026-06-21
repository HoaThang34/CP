#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<long long> res(n + 1);
    for(int i = 1; i <= n; ++i){
        long long max_val = -1e9;
        for(int j = i; j <= n; j += i){
            max_val = max(max_val, a[j]);
        }
        res[i] = max_val;
    }
    for(int i = 1; i <= n; ++i){
        cout << res[i] << ' ';
    }
    return 0;
}