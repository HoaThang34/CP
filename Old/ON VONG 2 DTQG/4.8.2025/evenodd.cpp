#include <bits/stdc++.h>
using namespace std;
long long t;
long long a, b;
long long gcd(long long a, long long b){
    long long tmp;
    while (b > 0){
        tmp = a% b;
        a = b;
        b = tmp;
    }
    return a;
}
#define task "evenodd"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        // cerr << gcd(a, b) << endl;
        if (gcd(a, b) % 2 == 0) cout << "even\n";
        else cout << "odd\n";
    }
    return 0;
}