/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CRUISE"
int n, m, k;
vector <pair<int, int>> a;
string s;
vector <char> dt;
void hoathang(){
    cin >> n >> m >> k;
    a.resize(n + 5);
    dt.resize(m + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m; i++){
        cin >> dt[i];
    }
    int id = 1;
    for (int i = 1; i <= k; i++){
        for (char x : dt){
            if (x == 'L') id = a[id].first;
            else if (x == 'R') id = a[id].second;

        }
    }
    cout << id << endl;
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
