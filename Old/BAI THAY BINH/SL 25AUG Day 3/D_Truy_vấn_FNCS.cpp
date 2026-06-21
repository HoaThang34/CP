#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long x, y;
long long u, v;
vector<long long> a;
vector<long long> l, r;
#define task "sol"
void subtask1(){
    int loai;
    cin >> loai;
    if(loai == 1){
        cin >> x >> y;
        a[x] = y;
    }
    else{
        cin >> u >> v;
        vector<long long> f(n + 1, 0);
        for(int i = 1; i <= n; i++){
            f[i] = f[i - 1] + a[i];
        }
        long long ans = 0;
        for(int i = u; i <= v; i++){
            long long sum = f[r[i]] - f[l[i] - 1];
            ans += sum;
        }
        cout << ans << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    l.resize(n + 1);
    r.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    cin >> q;
    while(q--){
        subtask1();
    }
    return 0;
}