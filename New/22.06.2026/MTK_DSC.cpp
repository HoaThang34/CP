/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "MTK_DSC"
#define endl '\n'
#define int long long
int n;
vector <vector<int>> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5, vector<int> (n + 5, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (a[i][j] == 1){
                cout << i << ' ' << j << endl;
            }
        }
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
