#include <bits/stdc++.h>
using namespace std;
long long n;
const long long MOD = 1000000007;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n == 2){
        cout << 3 << endl;
        return 0;
    }
    if(n == 3){
        cout << 6 << endl;
        return 0;
    }
    long long f1 = 1, f2 = 2, f3 = 3;
    long long s = 6; 
    for(long long i = 4; i <= n; i++){
        long long f4 = (f1 + f2 + f3) % MOD;
        s = (s + f4) % MOD;
        f1 = f2;
        f2 = f3;
        f3 = f4;
    }
    cout << s << endl;
    return 0;
}