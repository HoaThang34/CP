/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
#define endl '\n'
#define nap "BAI4"
int n;
vector <int> a;
// mang cong don
void sub1(){
    vector <long long> f(n + 5, 0);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + (long long)a[i];
    }
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s = f[j] - f[i - 1];
            if (s % 2 == 0) d++;
        }
    }
    cout << d << endl;
}
// segment tree
long long t[4 * N];
void build(int id, int l, int r){
    if (l == r){
        t[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
void upd(int id, int l, int r, int p, int v){
    if (p < l || p > r) return;
    if (l == r){
        t[id] = v;
        return;
    }
    int m = (l + r) / 2;
    upd(id * 2, l, m, p, v);
    upd(id * 2 + 1, m + 1, r, p, v);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
long long get(int id, int l, int r, int u, int v){
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return t[id];
    int m = (l + r) / 2;
    return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}
void sub2(){
    build(1, 1, n);
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long sum = get(1, 1, n, i, j);
            if (sum % 2 == 0) d++;
        }
    }
    cout << d << endl;
}
void sub3(){
    int cnt1 = 0, cnt2 = 0;
    long long s = 0;
    for (int i = 1; i <= n; i++){
        s += a[i];
        if (s % 2 == 0) cnt1++;
        else cnt2++;
    }
    long long ans1 = cnt1*(cnt1 - 1)/2, ans2 = cnt2*(cnt2 - 1)/2;
    cout << ans1 + ans2 + 1 << endl;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
//    sub1();
//    sub2();
//    sub3();
    if (n <= 1e2){
        sub1();
    }
    else if (n <= 1e3){
        sub2();
    }
    else sub3();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
