#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <bool> f(1e6 + 7, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i <= 1e6; i++){
        if (f[i]){
            for (int j = i*i; j <= 1e6; j+=i){
                f[j] = false;
            }
        }
    }
}
#define task "TWINS"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    sang();
    cin >> n >> k;
    long long cnt = 0;
    for (int i = 2; i + k <= n; i++){
        if (f[i] && f[i + k]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}