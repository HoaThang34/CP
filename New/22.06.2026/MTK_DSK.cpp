/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "MTK_DSK"
#define endl '\n'
#define int long long
int n;
vector <vector<int>> g;
void hoathang(){
    cin >> n;
    g.resize(n + 5);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x == 1){
                g[i].push_back(j);
//                g[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << i << " : ";
        for (int it : g[i]){
            cout << it << ' ';
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
