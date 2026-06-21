#include <bits/stdc++.h>
using namespace std;
long long n;
long long demuoc(long long n){
    long long d = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0) {
            d++;
            if (i != n/i){
                d++;
            }
        }
    }
    return d;
}
#define task "BAI1"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    while (n--){
        long long x;
        cin >> x;
        long long k = demuoc(x);
        if (k % 2 == 0){
            cout << "CHAN\n";
        }
        else cout << "LE\n";
        // cerr << demuoc(x) << ' ' << demuoc1(x) << endl;
    }
    return 0;
}