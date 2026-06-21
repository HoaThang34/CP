#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
void subtask1(){
    long long n = s.size();
    set<set<char>> a;
    for (int i = 0; i < n; i++){
        set<char> ans;
        for (int j = i; j < n; j++){
            ans.insert(s[j]);
            a.insert(ans);
        }
    }
    cout << a.size() + 1;
}
void subtask2(){
    long long n = s.size();
    set<vector<bool>> a;
    for (int i = 0; i < n; i++){
        vector<bool> check(30, false);
        for (int j = i; j < n; j++){
            check[s[j] - 'a'] = true;
            a.insert(check);
        }
    }
    cout << a.size() + 1;
}
#define task "distinct"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s;
//    subtask1();
    subtask2();
    return 0;
}
