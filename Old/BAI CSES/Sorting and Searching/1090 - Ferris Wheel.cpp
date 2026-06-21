#include <bits/stdc++.h>
using namespace std;
long long n, x;
vector <long long> a;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> x;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int d = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++){
        long long k = x - a[i];
        for (int j = n; j >= 1; j--){
            if (a[j] <= k){
                a.erase(a.begin() + i);
                a.erase(a.begin() + j);
                d++;
                break;
            }
        }
    }
    cout << d;
    return 0;
}