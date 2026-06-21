#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a, b;
#define task "HORSE"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());
    long long d = 0, j = n, i = n;
    while (i >= 1 && j >= 1){
        if (a[i] > b[j]){
            d++;
            j--; i--;
        }
        else if (a[i] <= b[j]){
            j--;
        }
    }
    cout << d;
    return 0;
}