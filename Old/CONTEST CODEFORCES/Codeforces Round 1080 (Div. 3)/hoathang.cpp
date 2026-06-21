/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
#define endl '\n'
#define nap "hoathang"
int n;
vector <int> a;
vector <vector<int>> f;
void hoathang(){
    cin >> n;
    a.resize(n);
    f.assign(n, vector<int> (7, N + 5));
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= 6; i++){
        if (a[0] == i){
            f[0][i] = 0;
        }
        else f[0][i] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= 6; j++){
            int s;
            if (a[i] == j){
                s = 0;
            }
            else s = 1;
            for (int k = 1; k <= 6; k++){
                if (j!=k && j + k != 7){
                    f[i][j] = min(f[i][j], f[i - 1][k] + s);
                }
            }
        }
    }
    int ans = N;
    for (int i = 1; i <= 6; i++){
        ans = min(ans, f[n - 1][i]);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
