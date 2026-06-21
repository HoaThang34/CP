#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
vector<long long> dp;
void subtask1(){
    dp.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        for(int j = 1; j <= i; j++){
            long long k = i - j + 1;
            if(a[j] == k - 1){
                if (j > 1){
                    dp[i] = max(dp[i], dp[j - 1] + k);
                }
                else{
                    dp[i] = k;
                }
            }
        }
    }
    cout << n - dp[n];
}
void subtask2(){
    dp.resize(n + 7, LLONG_MAX);
    dp[1] = 0;
    for (int i = 1; i <= n; i++){
        dp[i + 1] = min (dp[i + 1], dp[i] + 1);
        if (a[i] + i<= n){
            dp[i + a[i] + 1] = min(dp[i + a[i] + 1], dp[i]);
        }
    }
    cout << dp[n + 1];
}
#define task "GOODARR"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // subtask1();
    subtask2();
    // if (n <= 100){
    //     subtask1();
    // }
    // else{
    //     subtask2();
    // }
    return 0;
}