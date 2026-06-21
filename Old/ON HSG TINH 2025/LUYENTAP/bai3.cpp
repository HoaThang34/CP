/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = 1e6 + 5;
#define nap "bai3"
long long n;
vector <long long> f(MAXN, 0);
void sang(){
    for (int i = 1; i <= MAXN; i++){
        for (int j = i; j <= MAXN; j+=i){
            f[j] += i;
        }
    }
}
void hoathang(){
    sang();
    cin >> n;
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        long long n1 = x+x, n2 = f[x];
        if(n1 <= n2){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
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
