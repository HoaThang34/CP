#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
long long n, q, t;
long long l, r, x;
vector <long long> a;
long long loai1(long long l, long long r){
    long long sum = 0;
    for (long long i = l - 1; i < r; i++){
        sum += a[i];
    }
    return sum;
}
void loai2(long long l, long long r, long long x){
    for (long long i = l - 1; i < r; i++){
        a[i] = (a[i] & x); 
    }
}
void loai3(long long l, long long r, long long x){
    for (long long i = l - 1; i < r; i++){
        a[i] = (a[i]^x); 
    }
}
void subtask1(){
    if (t == 1){
        cin >> l >> r;
        cout <<loai1(l,r) << '\n';
    }
    else if (t == 2){
        cin >> l >> r >> x;
        loai2(l, r, x);
    }
    else if (t == 3){
        cin >> l >> r >> x;
        loai3(l, r, x);
    }
}
#define task "ANDXOR"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n);
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> q;
    while (q--){
        cin >> t;
        subtask1();
    }
    return 0;
}