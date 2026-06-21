#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long n;
string s;
vector<string> a;
vector<vector<long long>> f, g;
#define task "sol"
void subtask1(){
    while(cin >> n && n != 0){
        a.resize(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> s;
            a[i] = " " + s;
        }
        if(a[1][1] != a[n][n]){
            cout << 0 << endl;
            continue;
        }
        g.assign(n + 2, vector<long long>(n + 2, 0));
        g[1][n] = 1;
        for(int k = 1; k < n; k++){
            f.assign(n + 2, vector<long long>(n + 2, 0));
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    long long c1 = k + 2 - i;
                    long long c2 = 2 * n - k - j;
                    if(c1 < 1 || c1 > n || c2 < 1 || c2 > n){
                        continue;
                    }
                    if(a[i][c1] != a[j][c2]){
                        continue;
                    }
                    f[i][j] = (g[i][j] + g[i - 1][j] + g[i][j + 1] + g[i - 1][j + 1]) % MOD;
                }
            }
            g = f;
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            ans = (ans + g[i][i]) % MOD;
        }
        cout << ans << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    subtask1();
    return 0;
}