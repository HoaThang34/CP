/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N =1e6 + 5;
#define endl '\n'
#define nap "SPNUM"
#define int long long
long long a, b;
vector<bool> f(N, true);
void sang(){
    f[0] = f[1] =false;
    for (int i = 2; i*i < N; i++){
        if(f[i]){
            for (int j= i*i; j < N; j+=i){
                f[j] = false;
            }
        }
    }
}
void hoathang(){
    cin >> a >> b;
    int ans = 0;
    for (int i = 2; i <= N; i++){
        if (!f[i]) continue;
        int k = i*i;
        if (k >= a && k <= b) ans++;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang();
    hoathang();
    return 0;
}
