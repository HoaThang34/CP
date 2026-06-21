#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
long long sum(long long n){
    long long s = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0) {
            s += i;
            if (i != n/i){
                s+=n/i;
            }
        }
    }
    return s;
}
bool check(long long k){
    long long kk = 2*k;
    if(kk <= sum(k)){
        return true;
    }
    return false;
}
#define task "BAI3"
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
        if (check(a[i])){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }    
    // cerr << sum(18);
    return 0;
}