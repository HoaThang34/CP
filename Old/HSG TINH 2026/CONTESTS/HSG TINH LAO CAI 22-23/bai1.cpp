/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 5;
#define nap "bai1"
vector <bool> f(N, true);
vector <int> sum(N, 0);
vector <int> p;

void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; i++){
        if (f[i]){
            for (int j = i * i; j <= N; j += i){
                f[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++){
        if (f[i]){
            p.push_back(i);
        }
    }
}

void xuli(){
    sang();
    for (int i = 1; i < N; i++){
        sum[i] = sum[i/10] + (i % 10);
    }
    for (int i = 2; i < N; i++){
        int tmp = i;
        int s = 0;
        for (int j = 0; j < p.size() && p[j] * p[j] <= tmp; j++){
            while (tmp % p[j] == 0){
                s += sum[p[j]];
                tmp /= p[j];
            }
        }
        if (tmp > 1){
            s += sum[tmp];
        }
        f[i] = (s == sum[i]);
    }
}

int a, b;
void hoathang(){
    xuli();
    cin >> a >> b;
    int res = 0;
    for (int i = a; i <= b; i++){
        res += f[i];
    }
    cout << res << endl;
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
