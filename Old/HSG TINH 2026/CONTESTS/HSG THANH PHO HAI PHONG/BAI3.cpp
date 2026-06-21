/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BAI3"
int n;
vector <int> a;
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long s = 0, ans = -1e18;
    for (int i = 1; i <= n; i++){
        int x = a[i];
        s += x;
        ans = max(ans, s);
        if (s < 0){
            s = 0;
        }
    }
    ans = max(ans, s);
    cout << ans << endl;
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
