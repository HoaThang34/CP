/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "LIGHTS"

void hoathang(){
    long long n;
    cin >> n;
    long long res = sqrt(n);
    while (res * res > n) res--;
    while ((res + 1) * (res + 1) <= n) res++;
    cout << res << endl;
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
