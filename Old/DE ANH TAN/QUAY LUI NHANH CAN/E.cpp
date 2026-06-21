/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"
long long n;
vector <long long> a;
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <long long> ans;
    for (int i = 1; i <= n; i++){
        auto it = lower_bound(ans.begin(), ans.end(), a[i]);
        if (it == ans.end())
            ans.push_back(a[i]);
        else
            *it = a[i];
    }
    cout << ans.size() << endl;
//    for (long long x : ans){
//        cout << x << ' ';
//    }
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
