#include <bits/stdc++.h>
using namespace std;
long long n, d;
vector <long long> a;

#define task "TELEFONI"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> d;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long l = 1; 
    long long dem = 0;
    while(l < n){
        long long r = min(l + d, n);
        bool check = false;
        for(int i = r; i > l; i--){
            if(a[i] == 1){
                l = i;
                check = true;
                break;
            }
        }
        if(!check){ 
            dem++;
            a[r] = 1;
            l = r;
        }
    }
    cout << dem;
    return 0;
}