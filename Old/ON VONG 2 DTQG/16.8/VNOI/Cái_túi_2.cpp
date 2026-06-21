#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> w, v, a;
long long ans = 0;
void xl(long long p, long long t, long long val){
    if(p == n + 1){
        ans = max(ans, val);
        return;
    }
    for(int i = 0; i <= a[p]; i++){
        if(t + i * w[p] <= m){
            xl(p + 1, t + i * w[p], val + i * v[p]);
        }
    }
}
void subtask1(){
    xl(1, 0, 0);
    cout << ans;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    w.resize(n + 1);
    v.resize(n + 1);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i] >> a[i];
    }
    subtask1();
    
    return 0;
}