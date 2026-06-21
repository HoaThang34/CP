#include <bits/stdc++.h>
using namespace std;
#define task "tv"
const int MOD = 1000000000;
int n,l;
vector<vector<int>> a;
long long ans;
int sub1(){
    ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            vector<int> c(2*l);
            int x = 0, y = 0, p = 0;
            while(x < l && y < l){
                if(a[i][x] <= a[j][y]) c[p++] = a[i][x++];
                else                  c[p++] = a[j][y++];
            }
            while(x < l) c[p++] = a[i][x++];
            while(y < l) c[p++] = a[j][y++];
            ans = (ans + c[l-1]) % MOD;
        }
    }
    cout << ans;
    return 0;
}
int sub2(){
    ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int lo = min(a[i][0], a[j][0]);
            int hi = max(a[i][l-1], a[j][l-1]);
            int ret = lo;
            while(lo <= hi){
                int mid = lo + (hi - lo) / 2;
                int c1 = upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
                int c2 = upper_bound(a[j].begin(), a[j].end(), mid) - a[j].begin();
                if(c1 + c2 >= l){
                    ret = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }
            ans = (ans + ret) % MOD;
        }
    }
    cout << ans;
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> l;
    a.assign(n, vector<int>(l));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){
            cin >> a[i][j];
        }
    }
    if(n <= 50 && l <= 300) return sub1();
    else                  return sub2();
}
