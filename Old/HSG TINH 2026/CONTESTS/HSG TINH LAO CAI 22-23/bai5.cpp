/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai5"
string a, b;
int k, n;
vector<vector<int>> f;

void hoathang(){
    cin >> k >> a >> b;
    n = a.size();
    a = " " + a;
    b = " " + b;
    f.resize(n + 5, vector<int>(n + 5, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (abs(a[i] - b[j]) <= k){
                f[i][j] = f[i-1][j-1] + abs(a[i] - b[j]);
            }
            else f[i][j] = f[i-1][j-1];
        }
    }
    long long d = 0;
    for (int i = 1; i <= n - 2; i++){
        for (int j = i + 1; j <= n - 1; j++){
            int x = f[i][i];
            int y = f[j][j] - f[i][i];
            int z = f[n][n] - f[j][j];
            if (x == i && y == j - i && z == n - j){
                d++;
            }
        }
    }
    cout << d << endl;
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
