/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"
int n, m;
vector <vector <int>> g;
vector <int> d;

void hoathang(){
    cin >> n >> m;
    g.resize(n + 5);
    d.resize(n + 5, -1);
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
