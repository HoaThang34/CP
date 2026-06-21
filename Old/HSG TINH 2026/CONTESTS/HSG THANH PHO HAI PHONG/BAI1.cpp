/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BAI1"
int gcd(long long a, long long b){
    long long tmp;
    while(b){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
long long lcm(long long a, long long b){
    return (a*b)/gcd(a, b);
}
void hoathang(){
    long long l, r, a, b;
    cin >> l >> r >> a >> b;
    long long n1, n2, n3;
    n1 = (r/a) - (l-1)/a;
    n2 = (r/ b) - (l - 1)/b;
    n3 = (r/lcm(a, b)) - (l - 1)/lcm(a, b);
    long long ans = n1 + n2 - n3;
    cout << ans << endl;
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
