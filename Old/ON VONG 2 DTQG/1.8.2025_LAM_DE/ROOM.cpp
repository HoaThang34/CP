#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a, b;
vector <long long> p, ans;
long long rmin;
void xuli (long long i, long long st, long long s){
    if (i > n){
        if(s < rmin){
            rmin = s;
            for(int k = 1; k <= n; k++){
                ans[k] = p[k];
            }
        }
        return;
    }
    for(int j = st; j <= m - (n - i); j++){
        long long d = abs(a[i] - b[j]);
        p[i] = j;
        xuli (i + 1, j + 1, s + d);
    }
}   
#define task "ROOM"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= m; j++) cin >> b[j];
    p.resize(n + 1, 0);
    ans.resize(n + 1, 0);
    rmin = LLONG_MAX;
    xuli(1, 1, 0);
    cout << rmin << endl;
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}