#include <bits/stdc++.h>
using namespace std;

#define task ""
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long n;
    cin >> n;
    cout << n << ' ' <<  rand()%100 << '\n';
    for (int i = 1; i <= n; i++){
        cout << i << ' ';
    }
    return 0;
}