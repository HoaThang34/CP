/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "HORSE"
int n;
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
    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + n + 1);
    int d = 0, j = 1;
    for (int i = 1; i <= n; i++){
        if (a[i] > b[j]){
            d++;
            j++;
        }
    }
    cout << d<< endl;
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
