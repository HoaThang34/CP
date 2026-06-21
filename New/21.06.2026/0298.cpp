/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "0298"
#define endl '\n'
#define int long long
string s;
void hoathang(){
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x){
        cout << x << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
