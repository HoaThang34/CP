#include <bits/stdc++.h>
using namespace std;
string s;
 
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s;
    long long rmax = 0;
    long long i = 0;
    long long d = 1;
    long long n = s.size() - 1;
    for (int  i = 0; i <= n; i++){
        if (s[i] == s[i + 1]){
            d++;
        }
        else d = 1;
        rmax = max(rmax, d);
    }
    cout << rmax;
    return 0;
}