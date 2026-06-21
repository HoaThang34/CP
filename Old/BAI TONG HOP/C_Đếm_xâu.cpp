/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n;
map <string, long long> cnt;

void hoathang(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        string x;
        cin >> x;
        cnt[x]++;
    }
    for (pair <string, long long> p : cnt){
        cout << p.first << ' ' << p.second << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}