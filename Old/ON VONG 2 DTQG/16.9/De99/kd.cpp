#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a;
void nhap(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void subtask1(){ //tham lam
    long long s = 0;
    for (int i = 1; i <= n; i++){
        if (s < 0){
            s = 0;
        }
        else{
            s = s + a[i];
        }
    }
    cout << s;
}
void solve(){
    subtask1();
}
#define nap "kd"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    nhap();
    solve();
    return 0;
}
