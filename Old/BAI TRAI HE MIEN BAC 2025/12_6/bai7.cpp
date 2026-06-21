#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b;

void sub1(){
    int u = __gcd(a, b);
    ll l = 1LL * a * b / u;
    int x = 1, y = 1e9;
    for(int i = 1; i <= 100; i++){
        for(int j = i; j <= 100; j++){
            if(__gcd(i, j) != u) continue;
            if(1LL * i * j / u != l) continue;
            if(j - i < y - x){
                x = i;
                y = j;
            }
        }
    }
    cout << x << " " << y;
}

void sub2(){
    int g = __gcd(a, b);
    ll l = 1LL * a * b / g;
    ll m = l / g;
    ll p = 1, q = m, d = m - 1;
    for(ll i = 1; i * i <= m; i++){
        if(m % i != 0) continue;
        ll u = i, v = m / i;
        if(__gcd(u, v) != 1) continue;
        if(v - u < d){
            p = u;
            q = v;
            d = v - u;
        }
    }
    cout << g * p << " " << g * q;
}

#define task "sol"
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> a >> b;
    if(a <= 100 && b <= 100) sub1();
    else sub2();
    return 0;
}
