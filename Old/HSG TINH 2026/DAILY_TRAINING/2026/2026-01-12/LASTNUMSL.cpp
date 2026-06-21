/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "LASTNUMSL"
int n;
vector <int> f;
void hoathang(){
    cin >> n;
    f.resize(n + 5, 1);
    for (int i = 3; i <= n; i++){
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    }
    cout << f[n] << endl;

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
