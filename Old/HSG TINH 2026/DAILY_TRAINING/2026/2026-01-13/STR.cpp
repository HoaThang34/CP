/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "STR"
string s;
void hoathang(){
    cin >> s;
    int d = 0;
    for (char x : s){
        int k = x - '0';
        if (k != 0 && k != 1){
            d++;
        }
    }
    cout << d<< endl;
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
