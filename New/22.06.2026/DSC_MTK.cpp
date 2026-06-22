/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "DSC_MTK"
#define endl '\n'
#define int long long
int n, m;
vector <vector<int>> a;
void hoathang(){
    cin >> n >> m;
    a.resize(n + 5, vector <int> (m + 5, 0));
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
