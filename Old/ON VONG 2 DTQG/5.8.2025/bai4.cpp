#include <bits/stdc++.h>
using namespace std;
long long n, t;
vector<long long> p, s;
#define task "BAI4"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> t;
    p.resize(n + 1);
    s.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i] >> s[i];
    }
    long long ans = 0;
    for(int i = 2; i <= n; i++){
        long long sum = abs(p[i] - p[1]) + s[i];
        if(sum <= t) ans++;
    }
    cout << ans;
    return 0;
}