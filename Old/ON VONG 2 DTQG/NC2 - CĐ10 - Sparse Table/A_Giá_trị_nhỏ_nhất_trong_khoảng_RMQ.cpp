#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
vector <long long> t;
void build(long long id, long long l, long long r){
    if (l == r){
        t[id] = a[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1 , r);
    t[id] = min(t[id * 2], t[id * 2 + 1]);
}
long long getmin(long long id, long long l, long long r, long long u, long long v){
    if (v < l || u > r){
        return LLONG_MAX;
    }
    if (u <= l && v >= r){
        return t[id];
    }
    long long mid = (l + r) / 2;
    return min(getmin(id * 2, l, mid, u, v), getmin(id * 2 + 1, mid + 1, r, u, v));
}
#define task "RMQ"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    t.resize(4 * n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--){
        long long l, r;
        cin >> l >> r;
        cout << getmin(1, 1, n, l, r) << endl;
    }
    return 0;
}