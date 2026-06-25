/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap ""
#define endl '\n'
#define int long long
int n, x;
vector<int> a;

void hoathang(){
    cin >> n >> x;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int d = 0;
    for (int i = 1; i <= n; i++){
        if (binary_search(a.begin() + i + 1, a.begin() + 1 + n, x - a[i])){
            d++;
        }
    }
    cout << d<< endl;
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
