#include <bits/stdc++.h>
using namespace std;
long long n;

#define task "daochu"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    while (n--){
        pair<string, string> p;
        cin >> p.first >> p.second;
        cout << p.second << ' ' << p.first << endl;
    }    
    return 0;
}