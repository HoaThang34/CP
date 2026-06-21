#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <long long> a;
void xuli(long long l, long long r, long long x){
    int d = 0;
    while (l <= r){
        if (l != r){
            if (a[l] == x){
                d++;
            }
            if (a[r] == x){
                d++;
            }
        }
        else{
            if (a[l] == x){
                d++;
            }
        }
        l++; r--;
    }
    cout << d << '\n';
}
void nhap(){
    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void solve(){
    while (q--){
        long long l, r, x;
        cin >> l >> r >> x;
        xuli(l, r, x);
    }
}
#define nap "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    nhap();
    solve();
    return 0;
}
