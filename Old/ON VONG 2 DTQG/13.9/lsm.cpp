#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
vector <long long> f;
void pre(){
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
}
void subtask1(){
    pre();
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s = f[j] - f[i - 1];
            if (s > 0){
                long long len = j - i + 1;
                ans = max(ans, len);
            }
        }
    }
    if (ans == LLONG_MIN){
        cout << -1;
        return;
    }
    else{
        cout << ans;
    }
}
void subtask2(){
    pre();
    long long ans = -1;
    long long rmin = 0; 
    long long pos = 0;
    for(int j = 1; j <= n; j++){
        if (f[j] > rmin){
            ans = max(ans, j - pos);
        }        
        if (f[j] < rmin){
            rmin = f[j];
            pos = j;
        }
    }
    cout << ans;
}
#define task "lsm"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    f.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // subtask1();
    // subtask2();
    if (n <= 10000){
        subtask1();
    }
    else{
        subtask2();
    }
    return 0;
}