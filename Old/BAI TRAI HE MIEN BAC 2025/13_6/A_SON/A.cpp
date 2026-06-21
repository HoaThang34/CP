#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
ll l, r;
ll demuoc(ll n){
    ll res = 0;
    for (ll i = 1; i * i <= n; i++){
        if (n % i == 0){
            res++;
            if (i * i != n) res++;
        }
    }
    return res;
}
void sub1(){
    ll res = 0;
    for (ll i = l; i <= r; i++){
        res += demuoc(i);
    }
    cout << res << '\n';
}
void sub2() {
    ll res = 0;
    for (ll d = 1; d * d <= r; d++) {
        ll left = max(l, d * d);
        ll right = r;
        if (left > right) continue;
        ll cnt = (right / d) - ((left - 1) / d);
        res += cnt * 2;
        if (d * d >= l && d * d <= r) res--;
    }
    cout << res << '\n';
}
ll S(ll x) {
    ll res = 0;
    for (ll i = 1, nxt; i <= x; i = nxt + 1) {
        ll q = x / i;
        nxt = x / q;
        res += q * (nxt - i + 1);
    }
    return res;
}
void sub3(){
    ll res = S(r) - S(l - 1);
    cout << res << '\n';
}
#define task "sol"
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> l >> r;
    // if (l <= 1e6 && r <= 1e6) {
    //     sub1();
    // } else if (l <= 1e12 && r <= 1e12 && r - l <= 1e6) {
    //     sub2();
    // } else {
    //     sub3();
    // }
    sub3();
    return 0;
}

/*
Subtask 1: Brute force.
Subtask 2: Sàng ước số cho đoạn.
Subtask 3: Tổng số ước từ 1 đến x, dùng công thức S(x) = sum_{i=1}^x floor(x/i).
*/