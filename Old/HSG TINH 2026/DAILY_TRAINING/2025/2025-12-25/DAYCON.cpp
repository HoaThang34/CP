/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
#define endl '\n'
#define nap "DAYCON"
int n;
vector <int> a;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i*i < N; i++){
        if (f[i]){
            for (int j = i*i; j < N; j+=i){
                f[j] = false;
            }
        }
    }
}
void hoathang(){
    sang();
    cin >> n;
    vector <int> pos;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (f[x]){
            pos.push_back(i);
        }
    }
    if (pos.size() <= 1){
        cout << -1 << endl;
        return;
    }
    int ans = 1e9, last = pos[0];
    for (int x : pos){
        if (x - last == 0) continue;
        ans = min(ans, x - last + 1);
        last = x;
    }
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
