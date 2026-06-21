/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "TWINS"
int n, k;
vector<bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; i++){
        if (f[i]){
            for (int j = i*i; j <= N; j+=i){
                f[j] = false;
            }
        }
    }
}
void sub1(){
    int d = 0;
    for (int i = 2; i <= n; i++){
        if (f[i]){
            for (int j = i; j <= n; j++){
                if (f[j]){
                    if (j - i == k) d++;
                }
            }
        }
    }
    cout << d << endl;
}
void sub2(){
    int d = 0;
    vector <int> ans;
    for (int i = 2; i <= n; i++){
        if (f[i]) ans.push_back(i);
    }
    vector <int> cnt(N, 0);
    for (int x : ans){
        if (x >= k && cnt[x - k] > 0) d+=cnt[x - k];
        cnt[x]++;
    }
    cout << d << endl;
}
void hoathang(){
    cin >> n >> k;
    if (n <= 100) sub1();
    else sub2();
//    sub1();
//    sub2();
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
