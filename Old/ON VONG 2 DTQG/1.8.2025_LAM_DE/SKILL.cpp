#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
long long xuli(long long l, long long r){
  long long rmin = 0;
  while (l < r){
    if (a[l] > a[r]) rmin = a[r];
    else rmin = a[l];
    l++; r--;
  }
  return rmin*(l-r+1);
}
// void subtask1(){
//   long long ans = LLONG_MIN;
//   for (int i = 1; i <= n; i++){
//     for (int j = i + 1; j <= n; j++){
//       ans = max(ans, xuli(i, j));
//       // cout << i << ' ' << j << ' ' << xuli(i, j) << endl;
//     }
//   }
//   cout << ans;
// }
void subtask1(){
  long long ans = LLONG_MIN;
  for (int i = 1; i <= n; i++){
        long long rmin = a[i];
        for (int j = i; j <= n; j++){
            rmin = min(rmin, a[j]);
            ans = max(ans, rmin * (j - i + 1));
        }
    }
  cout << ans;
}
void subtask2(){
    stack <long long> st;
    long long ans = 0;
    a.push_back(0);
    for(int i = 1; i <= n + 1; i++){
        while(!st.empty() && a[st.top()] > a[i]){
            long long top = a[st.top()];
            st.pop();
            long long l = 1;
            if (!st.empty()) l = st.top() + 1;
            long long r = i - 1;
            ans = max(ans, top * (r - l + 1));
        }
        st.push(i);
    }
    cout << ans;
}
#define task "SKILL"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  // subtask1();
  // subtask2();
  if (n <= 3000){
    subtask1();
  }
  else subtask2();
  return 0;
}
