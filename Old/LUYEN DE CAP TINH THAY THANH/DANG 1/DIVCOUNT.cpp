/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DIVCOUNT"
long long n;
void hoathang(){
    cin >> n;
    long long d = 0;
    for (long long i = 1; i*i <= n; i++){
        if(n%i == 0){
            d++;
            if (i!=n/i){
                d++;
            }
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
