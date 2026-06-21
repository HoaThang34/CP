#include <bits/stdc++.h>
using namespace std;
const long long MOD = 111539786;
long long t, n;
void nhan(long long a[2][2], long long b[2][2]){
    long long c[2][2];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            a[i][j] = c[i][j];
        }
    }
}
long long binpow(long long n){
    long long arr[2][2] = {{1, 1}, {1, 0}};
    long long ans[2][2] = {{1, 0}, {0, 1}};
    while(n > 0){
        if(n % 2 == 1){
            nhan(ans, arr);
        }
        nhan(arr, arr);
        n /= 2;
    }
    return ans[0][1];
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> n;
        n++;
        if (n == 1){
            cout << 1 << endl;
        }
        else{
            cout << binpow(n) << endl;
        }
    }
    return 0;
}