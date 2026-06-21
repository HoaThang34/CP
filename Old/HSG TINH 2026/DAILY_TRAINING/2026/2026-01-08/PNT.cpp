/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "PNT"
int t, n;
vector <int> ans;
vector <int> f(N, 0);
void sang(){
    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N; j+=i){
            f[j]++;
        }
    }
    int k = 0;
    for (int i = 1; i <= N; i++){
        if (f[i] > k){
            ans.push_back(i);
            k = f[i];
        }
    }
}
void hoathang(){
    cin >> n;
    int rmax = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] >= rmax) {
            rmax = f[i];
            res = i;
        }
    }
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang();
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
