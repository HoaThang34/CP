/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e5 + 5;
#define nap "hoathang"
int n;
vector <bool> ok;

void hoathang(){
    cin >> n;
    ok.assign(N, false);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (!ok[x]){
            ok[x] = true;
            cnt++;
        }
    }
    while (true){
        int x = cnt;
        if (!ok[x]){
            ok[x] = true;
            cnt++;
        }
        else{
            ans = x;
            break;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--)
    hoathang();
    return 0;
}
