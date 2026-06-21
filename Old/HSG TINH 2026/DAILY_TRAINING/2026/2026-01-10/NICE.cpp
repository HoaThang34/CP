/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "NICE"
int n;
vector <int> a;
//bool check(vector <int> a){
//    if (a[1] == a.size() - 1) return true;
//    else return false;
//}
void sub1(){
    int rmax = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= n - i){
            rmax = max(rmax, a[i]);
        }
    }
    cout << n - rmax - 1 << endl;
}
vector <int> f;
void sub2(){
    for (int i = n; i >= 1; i--){
        f[i] = f[i + 1] + 1;
        if (i + a[i] <= n){
            f[i] = min(f[i], f[i + a[i] + 1]);
        }
    }
    cout << f[1] << endl;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    f.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sub2();
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
