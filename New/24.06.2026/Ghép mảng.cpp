/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap ""
#define endl '\n'
#define int long long
int n, m;
vector<int> a, b;
void hoathang(){
    cin >> n >> m;
    a.resize(n + 5, -1);
    b.resize(m + 5, -1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    // vector<int> c;
    // for (int i = 1; i <= n; i++){
    //     c.push_back(a[i]);
    // }
    // for (int i = 1; i <= m; i++){
    //     c.push_back(b[i]);
    // }
    // sort(c.begin(), c.end());
    // for (int x : c){
    //     cout << x << ' ';
    // }
    vector <int> c;
    int l  = 1, r = 1;
    while (l <= n && r <= m){
        if (a[l] <= b[r]){
            c.push_back(a[l]);
            l++;
        }
        else{
            c.push_back(b[r]);
            r++;
        }
    }
    while (l <= n){
        c.push_back(a[l]);
        l++;
    }
    while(r <= m){
        c.push_back(b[r]);
        r++;
    }
    for (int x : c){
        if (x != -1){
            cout << x << ' ';
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
