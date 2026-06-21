/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

long long n, x, y;

void hoathang(){
    cin >> n;
    while(n--){
        cin >> x >> y;
        long long z = max(x, y);
        long long t = (z - 1) * (long long)(z - 1);
        long long ans;
        if(z % 2 == 0){
            if(y == z) ans = t + x;
            else ans = t + 2*z - y;
        }else{
            if(x == z) ans = t + y;
            else ans = t + 2*z - x;
        }
        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(nap".inp","r")){
        freopen(nap".inp","r",stdin);
        freopen(nap".out","w",stdout);
    }
    hoathang();
    return 0;
}
