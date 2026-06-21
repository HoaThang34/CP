/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "0299"
#define endl '\n'
#define int long long
string s;
int x, y;
vector <int> a;
void hoathang(){
    getline(cin, s);
    cin >> x >> y;
    stringstream ss(s);
    int k;
    while (ss >> k){
        a.push_back(k);
    }
    a.insert(a.begin() + y, x);
    for (int j : a) cout << j << ' ';
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
