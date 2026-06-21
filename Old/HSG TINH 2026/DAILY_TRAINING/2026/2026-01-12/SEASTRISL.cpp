/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEASTRISL"
int n, m;
unordered_map<int, string> cnt;
void hoathang(){
    cin >> n >> m;
    while (n--){
        int x; string s;
        cin >> x >> s;
        cnt[x] = s;
    }
    while (m--){
        int x;
        cin >> x;
        if (!cnt.count(x)){
            cout << "Not found" << endl;
        }
        else cout << cnt[x] << endl;
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
