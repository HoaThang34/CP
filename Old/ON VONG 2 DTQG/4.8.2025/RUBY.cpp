#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
void sub1(){
    long long ans = 0;
    for (int l = 1; l <= n; l++){
        set<long long> s;
        for (int r = l; r <= n; r++){
            if (s.count(a[r])){
                break;
            }
            s.insert(a[r]);
            ans = max(ans, (long long)(r - l + 1));
        }
    }
    cout << ans;
}

void sub2(){
    long long ans = 0;
    for (int l = 1; l <= n; l++){
        vector<bool> vs(1001, false);
        for (int r = l; r <= n; r++){
            if (a[r] <= 1000 && vs[a[r]]){
                break;
            }
            if (a[r] <= 1000) vs[a[r]] = true;
            ans = max(ans, (long long)(r - l + 1));
        }
    }
    cout << ans;
}

#define task "RUBY"
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
    // if (n <= 100){
    //     sub1();
    // }
    // else sub2();
    sub1();
    return 0;
}