#include <bits/stdc++.h>
using namespace std;
long long n, l, r;
vector <long long> a;
void subtask1(){
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long sum = 0;
            for (int k = i; k <= j; k++){
                sum += a[k];
            }
            sum = abs(sum);
            if (sum >= l && sum <= r){
                // cerr << a[i] << ' ' << a[j] << endl;
                d++;
            }
        }
    }
    cout << d;
}
void subtask2(){
    vector <long long> pre (n + 1, 0);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s = pre[j] - pre[i - 1];
            s = abs(s);
            if (s >= l && s <= r){
                d++;
                // cerr << a[i] << ' ' << a[j] << endl;
            }
        }
    }
    cout << d;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> l >> r;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // subtask1();
    // subtask2();
    if (n <= 1000){
        subtask1();
    }
    else subtask2();
    return 0;
}