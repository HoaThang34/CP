/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

int t;
int n;
vector<long long> a;
vector<long long> u;
vector<long long> b;

void hoathang(){
    cin >> n;
    a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    u.resize(n);
    u[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        u[i] = max(u[i - 1], a[i]);
    }
    b.resize(n, -1e18);
    // for(int i = 0 ; i < n ; i++){
    //     b[i] = -1e18;
    // }
    for(int i = 1 ; i < n ; i += 2){
        b[i] = u[i];
    }
    for(int i = 0 ; i < n ; i += 2){
        long long lim = 1e18;
        if(i - 1 >= 0){
            lim = min(lim, b[i - 1] - 1);
        }
        if(i + 1 < n){
            lim = min(lim, b[i + 1] - 1);
        }
        b[i] = min(u[i], lim);
    }
    long long ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] > b[i]){
            ans += a[i] - b[i];
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

    cin >> t;
    while(t--){
        hoathang();
    }

    return 0;
}
