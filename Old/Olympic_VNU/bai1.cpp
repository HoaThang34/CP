/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "bai1"
int n;
void hoathang(){
    cin >> n;
    long long s = 0;
    for (int i = 1; i <= n - 1; i++){
        int x;
        cin >> x;
        s += x;
    }
    s = 0 - s;
    cout << s << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
