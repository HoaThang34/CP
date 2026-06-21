/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

int t;
int n, k;
vector<int> a, cnt, f;

void hoathang(){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cnt.resize(n + 5);
    for(int i = 1; i <= n; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    f.resize(n + 7);
    for(int i = n; i >= 1; i--) f[i] = f[i + 1] + cnt[i];
    int ans = 1;
    for(int d = n; d >= 1; d--){
        int f0 = (4 * d <= n) ? f[4 * d] : 0;
        int f1 = cnt[d];
        int f2 = (2 * d <= n)? cnt[2 * d]:0;
        int f3=(3 * d <= n) ? cnt[3 * d]:0;
        int t1 = f0 + f1 + f2 + f3;
        int t2 = n - t1;
        if(t2 <= k){
            ans = d;
            break;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(nap".inp","r")){
        freopen(nap".inp","r",stdin);
        freopen(nap".out","w",stdout);
    }
    cin>>t;
    while(t--){
        hoathang();
    }
    return 0;
}
