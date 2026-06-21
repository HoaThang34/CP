#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
#define task "sol"
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
    long long sum = 0;
    for (int i = 1; i <= n - 1; i++){
        if (a[i] > a[i + 1]){
            sum += a[i] - a[i + 1];
            a[i + 1] += a[i] - a[i + 1];
        }
        else continue;
    }
    cout << sum;
    return 0;
}