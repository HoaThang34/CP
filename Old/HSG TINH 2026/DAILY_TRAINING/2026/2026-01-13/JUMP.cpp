/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define endl '\n'
#define nap "JUMP"
int n, m, d;
vector<vector<int>> a, f;
string s;
void hoathang(){
    cin >> n >> m >> d;
    a.resize(n + 5, vector<int> (n + 5));
    f.resize(n + 5, vector<int> (n + 5));
    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 1; j <= m; j++){
            a[i][j] = s[j - 1] - '0';
        }
    }
    f[1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int s1 = a[i][j];
            for (int k = i - 1; k >= 1; k--){
                s1 += a[k][j];
                if (s1 > d) break;
                f[i][j] = (f[i][j] + f[k][j])%MOD;

            }
            int s2 = a[i][j];
            for (int k =j - 1; k >= 1; k--){
                s2 += a[i][k];
                if (s2 > d) break;
                else f[i][j] = (f[i][j] + f[i][k])%MOD;
            }
        }
    }
    cout << f[n][m] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
