/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "WORKING"
#define endl '\n'
#define int long long
int n;
vector <pair<int,int>> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    b.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].second >> a[i].first;
    }    
    sort(a.begin() + 1, a.begin() + 1 + n);
    int r = -1, ans = 0;
    for (int i = 1; i <= n; i++){
        if (a[i].second >= r){
            ans += a[i].first - a[i].second;
            r = a[i].first;
        }
    }
    cout << ans << endl;
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
