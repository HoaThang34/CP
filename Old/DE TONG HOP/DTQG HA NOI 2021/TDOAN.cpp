#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a;
vector <long long> f;

#define task "TDOAN"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n + 1);
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
        if (a[i] == k){
            cout << i << ' ' << 1;
            return 0;
        }
    }   
    long long ans1 = 0, ans2 = LLONG_MAX; 
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s = f[j] - f[i - 1];
            // cerr << i << ' ' << j << ' ' << s << '\n';
            if (s == k){
                long long dis = j - i + 1;
                // cerr << i << ' ' << dis << '\n';
                if (dis < ans2){
                    ans2 = dis;
                    ans1 = i;
                }
            }
        }
    }    
    if (ans2 == LLONG_MAX){
        cout << 0;
        return 0;
    }
    else{
        cout << ans1 << ' ' << ans2;
        return 0;
    }
    return 0;
}