/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "0295"
#define endl '\n'
#define int long long
string s;
char n;
map<char,int> cnt;
void hoathang(){
    getline(cin, s);
    cin >> n;
    for (char x : s){
        cnt[x]++;
    }
    for (pair<char, int> p : cnt){
        if (p.first != n){
            cout << p.first << ' ' << p.second << endl;
        }
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
