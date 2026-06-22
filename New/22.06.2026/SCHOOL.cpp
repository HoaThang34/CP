/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "SCHOOL"
#define endl '\n'
#define int long long
int n, m, k;
vector <vector<pair<int,pair<int,int>>>> g;

void hoathang(){
    cin >> n >> m >> k;
    g.resize(n + 5);
    for (int i = 1; i <= m; i++){
        int i,j,a,b;
        cin >> i >> j >> a >> b;
        g[i].push_back({j, {a, b}});
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
