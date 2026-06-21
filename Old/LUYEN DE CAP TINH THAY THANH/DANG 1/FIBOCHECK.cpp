/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "FIBOCHECK"

long long k;
void hoathang(){
    cin >> k;
    if (k == 0 || k == 1) {
        cout << "YES" << endl;
        return;
    }
    long long a = 0, b = 1, c = 0;
    while (c < k) {
        c = a + b;
        a = b;
        b = c;
    }
    if (c == k) cout << "YES" << endl;
    else cout << "NO" << endl;
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
