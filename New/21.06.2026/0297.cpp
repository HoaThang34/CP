/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "0297"
#define endl '\n'
#define int long long
string s;
int x;
vector <int> a;
void hoathang(){
    getline(cin, s);
    cin >> x;
    stringstream ss (s);
    int k;
    while (ss >> k){
        a.push_back(k);
    }
    reverse(a.begin(), a.end());
    for (int i = x; i <= a.size() - 1; i++){
        cout << a[i] << ' ';
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
