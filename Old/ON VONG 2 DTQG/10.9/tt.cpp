#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
long long xuli(long long n){
    vector<long long> f(n + 1, 0);
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        if(i % 2 != 0){
            f[i] = f[i-1];
        } else {
            f[i] = f[i-1] + f[i/2];
        }
    }
    return f[n];
}
void subtask1(){
    for (int i = 1; i <= n; i++){
        cout << xuli(a[i]) << '\n';
    }
}
#define task "tt"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <=n; i++){
        cin >> a[i];
    }
    subtask1();
    return 0;
}