/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"
int n;
void hoathang(){
    cin >> n;
    int p1 = max(1, n-26-26);
    int k = n - p1;
    int p2 = max(1, k -26);
    int p3 = n - p1 - p2;
    char c1 = 'a' + p1 - 1;
    char c2 = 'a' + p2 - 1;
    char c3 = 'a' + p3 - 1;
    cout << c1 << c2 << c3 << endl;
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
