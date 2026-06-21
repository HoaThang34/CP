#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long m, n;
vector <vector <long long>> a;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 1; i * i <= N; i++){
        if (f[i]){
            for (int j = i * i; j <= N; j+=i){
                f[j] = false;   
            }
        }
    }
}
#define task "nguyento"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        // freopen(task".out", "w", stdout);
    }
    sang();
    int d = 0;
    cin >> m >> n;
    a.resize(m + 1, vector <long long> (n + 1));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (f[a[i][j]]){
                d++;
            }
        }
    }    
    cout << d;
    return 0;
}