#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long d = 0;
vector <long long> a;
vector <long long> b;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    a.resize(n + 1);
    b.resize(m + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    sort (a.begin(), a.end());  
    sort (b.begin(), b.end());
    long long i = 1, j = 1;
    while (i <= n && j <= m){
        long long res = abs(a[i] - b[j]);
        if (res <= k){
            i++; j++;
            d++;
        }
        else{
            if (a[i] < b[j]){
                i++;
            }
            else j++;
        }
    }
    cout << d;
    return 0;
}