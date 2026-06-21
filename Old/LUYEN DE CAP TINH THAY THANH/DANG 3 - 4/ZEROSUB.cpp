/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap ""
int n;

void hoathang(){
    cin >> n;
    long long s = 0, ans = 0;
    unordered_map<long long, long long> cnt;
    cnt[0] = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s += x;
        if (cnt.find(s) != cnt.end()){
            ans = max(ans, i - cnt[s]);
        }
        else {
            cnt[s] = i;
        }
    }
    cout << ans<< endl;
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
