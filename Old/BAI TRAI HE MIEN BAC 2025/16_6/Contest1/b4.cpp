#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"

ll gcd(ll x, ll y){
    while (y){ ll t = x % y; x = y; y = t; }
    return x;
}

void subtask1(ll k, ll a){
    ll l = 1, r = (ll)2e15, ans = r;
    auto count1 = [&](ll x){ return x - x / a; };
    while (l <= r){
        ll mid = l + (r - l) / 2;
        if (count1(mid) >= k){ ans = mid; r = mid - 1; }
        else l = mid + 1;
    }
    cout << ans << "\n";
}

void subtask2(ll k, ll a, ll b){
    ll l = 1, r = (ll)2e15, ans = r;
    auto count2 = [&](ll x){
        ll g = gcd(a, b);
        int bc = ( (int)a / g ) * b;
        ll lcm = bc > (int)2e15 ? (ll)2e15 : (ll)bc;
        return x - x / a - x / b + x / lcm;
    };
    while (l <= r){
        ll mid = l + (r - l) / 2;
        if (count2(mid) >= k){ ans = mid; r = mid - 1; }
        else l = mid + 1;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        ll a, b = 0; cin >> a;
        if (n == 1) subtask1(k, a);
        else { cin >> b; subtask2(k, a, b); }
    }
    return 0;
}
