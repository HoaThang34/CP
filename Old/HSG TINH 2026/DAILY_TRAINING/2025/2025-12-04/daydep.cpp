/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "daydep"
int n;
vector <int> a;
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    map <int, int> cnt;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int d = 0;
    for (pair <int, int> p : cnt){
        if (p.first <= p.second)
            d += p.first;
    }
    cout << n - d << endl;
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
