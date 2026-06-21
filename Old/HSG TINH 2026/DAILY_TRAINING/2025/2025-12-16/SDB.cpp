/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 5;
#define nap "SDB"
int n;
vector <bool> f (N, true);
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
    vector <int> p;
    for (int i = 2; i < N; i++){
        if (f[i]){
            p.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        long long k = sqrt(x);
        if (k*k < x){
            k++;
        }
        auto it = lower_bound(p.begin(), p.end(), k);
        long long ans = *it;
        cout << ans*ans << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
