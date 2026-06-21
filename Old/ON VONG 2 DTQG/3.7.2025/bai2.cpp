#include <bits/stdc++.h>
using namespace std;
long long n;
int m;
map<long long, int> a;
long long res = 0, dem = 0, k = 0, p = 1;

#define task "chiakeo"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    while(m--){
        long long l, r;
        cin >> l >> r;
        if(l <= r){
            a[l]++;
            a[r + 1]--;
        }else{
            a[1]++;
            a[r + 1]--;
            a[l]++;
        }
    }
    for(auto it : a){
        long long x = it.first;
        int val = it.second;
        if(x > n + 1) continue;
        long long len = x - p;
        if(len > 0){
            if(k > res){
                res = k;
                dem = len;
            }else if(k == res){
                dem += len;
            }
        }
        k += val;
        p = x;
    }
    if(p <= n){
        long long len = n - p + 1;
        if(k > res){
            res = k;
            dem = len;
        }else if(k == res){
            dem += len;
        }
    }
    cout << res << " " << dem;
    return 0;
}
