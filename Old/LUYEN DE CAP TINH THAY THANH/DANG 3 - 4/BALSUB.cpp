/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "balsub"

int n, ans = 0;
vector<int> a;
map<int, int> mp;

void hoathang(){
    if (!(cin >> n)) return;
    a.resize(n + 5);
    int s = 0;
    mp[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1) s++;
        else s--;
        if (mp.count(s)){
            ans = max(ans, i - mp[s]);
        }
        else{
            mp[s] = i;
        }
    }
    cout << ans;
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