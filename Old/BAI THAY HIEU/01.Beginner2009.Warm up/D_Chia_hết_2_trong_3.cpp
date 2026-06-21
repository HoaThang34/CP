#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    long long n, p, q, r;
    while(cin >> n >> p >> q >> r){
        long long pq = n / lcm(p, q);
        long long pr = n / lcm(p, r);
        long long qr = n / lcm(q, r);
        long long pqr = n / lcm(lcm(p, q), r);
        
        long long kq = pq + pr + qr - 3 * pqr;
        
        cout << kq << endl;
    }
    
    return 0;
}