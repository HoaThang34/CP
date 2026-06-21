/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "XAUDEP"
int n;
string s;
void hoathang(){
    cin >> n;
    cin >> s;
    long long d = 0, rmax = -1e18;
    for (int i = 1; i <= n; i++){
        char x = s[i - 1];
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            d++;
        }
        else{
            rmax = max(rmax, d);
            d = 0;
        }
    }
    rmax = max(rmax, d);
    if (rmax == 0) rmax = -1;
    cout << rmax << endl;
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
