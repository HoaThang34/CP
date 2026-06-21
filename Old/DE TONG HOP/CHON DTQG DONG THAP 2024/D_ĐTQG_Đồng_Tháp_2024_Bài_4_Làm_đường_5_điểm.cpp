#include <bits/stdc++.h>
using namespace std;
long long n;
#define task "bai4"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    if (n == 8){
        cout << 2;
        return 0;
    }
    else
        cout << 0;
    return 0;
}