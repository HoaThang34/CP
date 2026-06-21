/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "NONZERO"
int n;
int x;
void hoathang(){
    cin >> n;
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == 0){
            ans++;
            sum++;
        } else {
            sum += x;
        }
    }
    if (sum == 0){
        ans++;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;

    while (t--) hoathang();
    return 0;
}
