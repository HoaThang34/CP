#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, q;
vector<long long> a;
long long st[4 * N];
long long gcd(long long x, long long y){
    while(y){
        long long t = x % y;
        x = y;
        y = t;
    }
    return x;
}
void subtask1(){
    long long l, r;
    long long x;
    cin >> l >> r >> x;
    long long cnt = 0;
    for(long long i = l; i <= r; i++){
        long long g = a[i];
        for(long long j = i; j <= r; j++){
            if(j > i) g = gcd(g, a[j]);
            if(g >= x) cnt++;
            else break;
        }
    }
    cout << cnt << endl;
}
void build(long long id, long long l, long long r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    long long mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = __gcd(st[id << 1], st[id << 1 | 1]);
}
long long get(long long id, long long l, long long r, long long u, long long v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return st[id];
    long long mid = (l + r) >> 1;
    return __gcd(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}
void subtask2(){
    long long l, r;
    long long x;
    cin >> l >> r >> x;
    long long cnt = 0;
    for(long long i = l; i <= r; i++){
        long long lo = i, hi = r, j = i;
        long long g = 0;
        while(j <= r){
            g = get(1, 1, n, i, j);
            if(g < x) break;
            cnt++;
            j++;
        }
    }
    cout << cnt << endl;
}
#define task "GCD"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> q;
    a.resize(n + 1);
    for(long long i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        if (n <= 100) subtask1();
        else subtask2();
    }
    return 0;
}
