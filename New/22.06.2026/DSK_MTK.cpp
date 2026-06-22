/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "DSK_MTK"
#define endl '\n'
#define int long long
int n;
vector <vector <int>> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5, vector <int> (n + 5, 0));
    string s;
    for (int i = 1; i <= n; i++){
//        cerr << i << endl;
        getline(cin, s);
        int u;
        stringstream ss(s);
        while (ss >> u){
//            cout << u << ' ';
            a[i - 1][u] = 1;
            a[u][i - 1] = 1;
//            cout << i << ' ' << u << endl;
//            cout << i << endl;
        }
//        cout << endl;
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
