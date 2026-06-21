/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "0296"
#define endl '\n'
#define int long long
string s;
int x;
vector <int> a;
void hoathang(){
    getline(cin, s);
    stringstream ss(s);
    while (ss >> x){
        a.push_back(x);
    }
    reverse(a.begin(), a.end());
    for (int k : a) cout << k << ' ';
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
