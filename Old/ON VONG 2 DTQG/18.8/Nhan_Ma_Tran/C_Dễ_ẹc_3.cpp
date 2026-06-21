#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    if(n == 1){
        cout << 1 << endl;;
        return 0;
    }
    if(n == 2){
        cout << 2 << endl;;
        return 0;
    }
    if(n == 3){
        cout << 3 << endl;;
        return 0;
    }
    long long f1 = 1, f2 = 2, f3 = 3, f4;
    for(long long i = 4; i <= n; i++){
        f4 = (3 * f3 + 2 * f2 + f1 + 10) % MOD;
        f1 = f2;
        f2 = f3;
        f3 = f4;
    }
    cout << f3 << endl;
    return 0;
}