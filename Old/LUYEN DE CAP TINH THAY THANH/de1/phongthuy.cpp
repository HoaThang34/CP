/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang(){
    string n;
    cin >> n;
    int s = 0;
    for(char c : n) s += c - '0';
    if(s < 2){
        cout << "NO";
        return;
    }
    for(int i = 2; i * i <= s; ++i){
        if(s % i == 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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