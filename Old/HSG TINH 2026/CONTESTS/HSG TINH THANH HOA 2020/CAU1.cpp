/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU1"
int x, y;
int gcd(int a, int b){
    int tmp;
    while (b){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void hoathang(){
    cin >> x >> y;
    int g = gcd(x, y);
    int d = 0;
    for (int i = 1; i*i <= g; i++){
        if (g % i == 0){
            d++;
            if (i != g/i){
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
