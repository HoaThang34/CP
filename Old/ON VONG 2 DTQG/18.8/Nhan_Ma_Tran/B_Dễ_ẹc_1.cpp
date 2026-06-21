#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long n;
void nhan(long long a[3][3], long long b[3][3]){
    long long c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = 0;
            for(int k = 0; k < 3; k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = c[i][j];
        }
    }
}
long long binpow(long long n){
    if(n <= 3) return n;
    long long base[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    long long res[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    n = n - 3;
    while(n > 0){
        if(n % 2 == 1){
            nhan(res, base);
        }
        nhan(base, base);
        n /= 2;
    }
    
    return (3 * res[0][0] + 2 * res[0][1] + 1 * res[0][2]) % MOD;
}

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    // n++;
    if(n == 1){
        cout << 1;
        return 0;
    }
    else if(n == 2){
        cout << 2;
        return 0;
    }
    else if(n == 3){
        cout << 3;
        return 0;
    }
    else{
        cout << binpow(n);
        return 0;
    }
    return 0;
}