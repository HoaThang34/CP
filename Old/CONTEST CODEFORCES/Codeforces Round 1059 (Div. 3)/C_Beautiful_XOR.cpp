/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
long long get_msb(long long n){
    long long m = 1;
    while ((m << 1) <= n && (m << 1) > 0){
        m <<= 1;
    }
    return m;
}
void hoathang(){
    long long a, b;
    cin >> a >> b;
    if (a == b){
        cout << 0 << endl << endl;
        return;
    }
    if (a > b){
        if ((a ^ b) < a){
            cout << 1 << endl;
            cout << (a ^ b) << endl;
        } else {
            long long m = get_msb(b);
            long long x1 = m;
            long long a1 = a ^ x1;
            long long x2 = a1 ^ b;
            cout << 2 << endl;
            cout << x1 << " " << x2 << endl;
        }
        return;
    }
    long long ma = get_msb(a);
    long long mb = get_msb(b);
    if (ma < mb){
        cout << -1 << endl;
    } else {
        long long a_prime = a ^ ma;
        if (a_prime == 0){
            long long x1 = 1;
            long long a1 = a ^ x1;
            long long x2 = a1 ^ b;
            cout << 2 << endl;
            cout << x1 << " " << x2 << endl;
        } else {
            long long x1 = a_prime;
            long long b_prime = b ^ mb;
            long long x2 = b_prime;
            cout << 2 << endl;
            cout << x1 << " " << x2 << endl;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}