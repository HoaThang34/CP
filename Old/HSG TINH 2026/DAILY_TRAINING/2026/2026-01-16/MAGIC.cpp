/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "MAGIC"
int n, q;
vector <int> a, b;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    b.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    cin >> q;
    while (q--){
        int x, y;
        cin >> x >> y;
        set <int> s1, s2;
        for (int i = 1; i <= x; i++){
            s1.insert(a[i]);
        }
        for (int i = 1; i <= y; i++){
            s2.insert(b[i]);
        }
        if (s1 == s2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
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
