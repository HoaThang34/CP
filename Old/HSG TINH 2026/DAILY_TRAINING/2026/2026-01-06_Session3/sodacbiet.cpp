/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int NMAX = 3e6 + 5;
#define endl '\n'
#define nap "sodacbiet"
int l, r;
vector <long long> f(NMAX, 0);
void hoathang(){
    for (int i = 1; i <= NMAX; i++){
        for (int j = i; j <= NMAX; j+=i){
            f[j] += i;
        }
    }
    cin >> l >> r;
    int d = 0;
    for (int i = l; i <= r; i++){
        long long s = f[i] - i;
        if (s > i){
            d++;
        }
    }
    cout << d << endl;
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
