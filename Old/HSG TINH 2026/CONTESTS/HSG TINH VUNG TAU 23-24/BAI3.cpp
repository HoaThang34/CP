/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define endl '\n'
#define nap "BAI3"
int n, k;
vector <vector<int>> f (1005, vector <int> (1005));
void hoathang(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        f[i][0] = 1;
        f[i][i] = 1;
        for (int j = 1; j < i; j++){
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
        }
    }
    cout << f[n][k] << endl;
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
