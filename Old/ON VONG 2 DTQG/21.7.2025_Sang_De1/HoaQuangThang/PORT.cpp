#include <bits/stdc++.h>
using namespace std;
long long n;
vector<tuple<long long, long long, long long>> a;
vector <long long> ans;
#define task "PORT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
      long long start, end;
      cin >> start >> end;
      a[i] = {end, start, i}; 
    }
    sort (a.begin(), a.end());
    long long res = 0;
    long long rmax = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
      auto [end, start, index] = a[i];
      if (start >= rmax) {
          rmax = end;
          res++;
          ans.push_back(index);
      }
    }
    cout << res << endl;
    for (long long x : ans) cout << x << endl;
    return 0;
}