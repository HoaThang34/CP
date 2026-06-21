#include <bits/stdc++.h>
using namespace std;
long long n;
vector<vector<long long>> c;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    c.resize(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    vector<long long> p(n);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    long long ans = LLONG_MAX;
    do{
        long long cur = 0;
        for(int i = 0; i < n - 1; i++){
            cur += c[p[i]][p[i + 1]];
        }
        ans = min(ans, cur);
    } while(next_permutation(p.begin(), p.end()));
    cout << ans;
    return 0;
}