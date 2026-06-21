/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "CCHUX"
long long n, k;
vector <vector <long long>> a;
void sub1(){
    long long rmax = -1e18;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            rmax = max(rmax, a[i][j]);
        }
    }
    cout << rmax << endl;
}
void sub2(){
    vector <vector <long long>> d1(n + 5, vector<long long>(n + 5, 0));
    vector <vector <long long>> d2(n + 5, vector<long long>(n + 5, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            d1[i][j] = a[i][j] + d1[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = n; j >= 1; j--){
            d2[i][j] = a[i][j] + d2[i - 1][j + 1];
        }
    }
    long long ans = -1e18;
    for (int i = 1; i <= n - k + 1; i++){
        for (int j = 1; j <= n - k + 1; j++){
            long long s1 = d1[i + k - 1][j + k - 1] - d1[i - 1][j - 1];
            long long s2 = d2[i + k - 1][j] - d2[i - 1][j + k];
            long long s = s1 + s2;
            if (k % 2 == 1){
                s -= a[i + k / 2][j + k / 2];
            }
            if (s > ans){
                ans = s;
            }
        }
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> n >> k;
    a.resize(n + 5, vector <long long> (n + 5));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (k == 1)
        sub1();
    else sub2();
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
