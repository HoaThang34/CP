#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long a[500005];
long long v[500005];
long long par[500005], len[500005];
long long sum[500005];
bool check[500005];
long long rmax;
long long res[500005];
long long find(long long x){
    return par[x] == x ? x : par[x] = find(par[x]);
}
void union_sets(long long x, long long y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(len[x] < len[y]){
        long long tmp = x;
        x = y;
        y = tmp;
    }
    par[y] = x;
    len[x] += len[y];
    sum[x] += sum[y];
    if(sum[x] > rmax) rmax = sum[x];
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= t; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        par[i] = i;
        len[i] = 1;
        check[i] = true;
        sum[i] = a[i];
    }
    for(int i = 1; i <= t; i++){
        check[v[i]] = false;
        sum[v[i]] = 0;
    }
    rmax = 0;
    for(int i = 1; i <= n; i++){
        if(!check[i]) continue;
        if(a[i] > rmax) rmax = a[i];
        if(i > 1 && check[i-1]) union_sets(i, i-1);
    }
    for(int i = t; i >= 1; i--){
        res[i-1] = rmax;
        long long p = v[i];
        check[p] = true;
        sum[p] = a[p];
        par[p] = p;
        len[p] = 1;
        if(a[p] > rmax) rmax = a[p];
        if(p > 1 && check[p-1]) union_sets(p, p-1);
        if(p < n && check[p+1]) union_sets(p, p+1);
    }
    for(int i = 0; i < t; i++) cout << res[i] << "\n";
    return 0;
}