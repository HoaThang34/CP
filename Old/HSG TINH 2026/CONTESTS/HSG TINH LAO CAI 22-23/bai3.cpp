/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 3*1e6 + 5;
#define nap "bai3"
vector<bool> f(N, 1);
vector<int> p(N, 0);

void sang(){
    f[0] = f[1] = 0;
    for (int i = 2; i * i < N; i++){
        if (f[i]){
            for (int j = i * i; j < N; j += i){
                f[j] = 0;
            }
        }
    }
}
int sum(int n){
    int s = 0;
    while (n > 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}
void sang1(){
    sang();
    for (int i = 1; i < N; i++){
        p[i] = p[i - 1];
        if (f[i] && sum(i) % 5 == 0){
            p[i]++;
        }
    }
}
void hoathang(){
    int l, r;
    cin >> l >> r;
    cout << p[r] - p[l - 1] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang1();
    int t; cin >> t;
    while (t--){
        hoathang();

    }
    return 0;
}
