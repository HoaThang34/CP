/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "GTONGSPO"
int n;
unordered_map<int, int> cnt;
void hoathang(){
    cin >> n;
    int d = 1;
    vector <int> a, b;
    while (n--){
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    for (int x : a){
        cnt[x] = d;
        d++;
    }
    for (int x : b){
        cout << cnt[x] << ' ';
    }
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
