#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long n;
vector <long long> a;
vector <long long> dp;
void subtask1(){
  long long ans = 0;
  for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                dp[i] += dp[j];
            }
        }
        ans += dp[i];
    }
  cout << ans % MOD;
}
#define task "DOANHSO"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n;
  a.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 1; i <= n ; i++){
    cin >> a[i];
  }
  subtask1();
  return 0;
}
