/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "MAVACH"

void hoathang(){
    string s;
    if (!(cin >> s)) return;
    
    int le = 0, chan = 0;
    for(int i = 0; i < 12; i++){
        int v = s[i] - '0';
        if((i + 1) % 2 != 0) le += v;
        else chan += v;
    }
    
    int S = le + 3 * chan;
    int M = S % 10;
    int C = (M == 0) ? 0 : 10 - M;
    
    if((s[12] - '0') == C) cout << "YES";
    else cout << "NO";
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