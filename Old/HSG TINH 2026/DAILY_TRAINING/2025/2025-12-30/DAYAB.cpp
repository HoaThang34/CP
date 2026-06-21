/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "DAYAB"
int n, m;
vector <int> a, b;
void hoathang(){
    cin >> n >> m;
    a.resize(n + 5);
    b.resize(m + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m ; i++){
        cin >> b[i];
    }
    unordered_map<int, int> cnt;
    for (int i = 1; i <= m; i++){
        cnt[b[i]]++;
    }
    unordered_set<int> st;
    for (int i = 1; i <= n; i++){
        if (cnt[a[i]] > 0){
            cout << a[i] << ' ';
            cnt[a[i]] = -1;
        }
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        if (cnt[a[i]] == 0){
            cout << a[i] << ' ';
            cnt[a[i]] = -1;
        }
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
