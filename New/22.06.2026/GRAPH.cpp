/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "GRAPH"
#define endl '\n'
#define int long long
int n, m;
vector <vector<int>> a;
void hoathang(){
    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        cout << i << ' ';
        for (int x : a[i]){
            cout << x << ' ';
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
