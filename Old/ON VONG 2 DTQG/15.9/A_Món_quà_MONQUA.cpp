#include <bits/stdc++.h>
using namespace std;
long long n;

#define task "monqua"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    long long ans = 1;
    while (ans * 2 <= n){
        ans = ans*2;
    }
    cout << ans;
    return 0;
}