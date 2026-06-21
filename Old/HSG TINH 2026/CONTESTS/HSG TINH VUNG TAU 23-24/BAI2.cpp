/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "BAI2"
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
vector <int> p(N, 0);
void xuli(){
    for (int i = 1; i <= N; i++){
        if (f[i]){
            p[i] = p[i - 1] + 1;
        }
        else p[i] = p[i - 1] + 0;
    }
}
long long n;
void hoathang(){
    cin >> n;
    long long ans = p[sqrt(n)];
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang();
    xuli();
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
