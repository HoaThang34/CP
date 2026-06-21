/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "XOASO"
int n;
unordered_map <int, int> cnt;

void hoathang(){
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector <int> ans;
    for (pair<int, int> p : cnt){
        if (p.second > 1){
                continue;
        }
        ans.push_back(p.first);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' ';
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
