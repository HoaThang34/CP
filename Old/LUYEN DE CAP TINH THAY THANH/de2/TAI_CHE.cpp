/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" 

void hoathang(){
    int n;
    cin >> n;
    map<int, int> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d[x]++;
    }
    int res = -1, mx = -1;
    for (auto const& x : d) {
        if (x.second > mx) {
            mx = x.second;
            res = x.first;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}