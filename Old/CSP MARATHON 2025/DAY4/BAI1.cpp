#include <bits/stdc++.h>
using namespace std;
string s;
#define task "sol"
bool check(string s){
    stack<char> st;
    for(char c: s){
        if(c == '(' || c == '[' || c == '{' || c == '<') st.push(c);
        else if(c == ')' && st.empty() || c == ']' && st.empty() || c == '}' && st.empty() || c == '>' && st.empty()) return false;
        else if((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{') || (c == '>' && st.top() == '<')) st.pop();
        else return false;
    }
    return st.empty();
}
void subtask1(){
  cin >> s;
  long long rmax = 0;
  long long n = s.size() - 1;
  for (long long i = 0; i <= n; i++){
    for (long long j = i; j <= n; j++){
      string s1 = s.substr(i, j - i + 1);
      if (check(s1)) rmax = max(rmax, j - i + 1);
    }
  }
  cout << rmax;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  subtask1();
  // cin >> s;
  // if (check(s)) cout << "Y";
  // else cout << "NO";
  return 0;
}
