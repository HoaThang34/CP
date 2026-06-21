#include <bits/stdc++.h>
using namespace std;
#define task "sol"
long long xuli(long long n, long long k){
    vector<string> ans;
    for(int i = 1; i <= n; i++){
        ans.push_back(to_string(i));
    }
    sort(ans.begin(), ans.end());
    string s = to_string(k);
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == s){
            return i + 1;
        }
    }
    return -1;
}
void subtask1(){
    long long k, m;
    cin >> k >> m;
    long long res = 0;
    for(int n = k; n <= 1e9; n++){
        if(xuli(n, k) == m){
            res = n;
            break;
        }
    }
    cout << res << endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    while(t--){
        subtask1();
    }
    return 0;
}