/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6 + 5;
#define endl '\n'
#define nap "SDB"
vector <int> f(NMAX, 0);
void sangdem(){
    for (int i = 1; i <= NMAX; i++){
        for (int j = i; j <= NMAX; j+=i){
            f[j]++;
        }
    }
}
long long sum(int n){
    long long s = 0;
    while (n){
        s += n%10;
        n/=10;
    }
    return s;
}
bool check(int n){
    if (sum(n) % 3 == 0 && f[n] == 9){
        return true;
    }
    return false;
}
vector <int> p (NMAX, 0);
void sang(){
    for (int i = 1; i <= NMAX; i++){
        if (check(i)){
            f[i] = f[i - 1] + 1;
        }
        else f[i] = f[i - 1] + 0;
    }
}
int a, b;
void hoathang(){
    cin >> a >> b;
    int ans = f[b] - f[a - 1];
    cout << ans << endl;

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sangdem();
    sang();
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
