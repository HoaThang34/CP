#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6+5;
long long n, k;
vector <long long> a;
// vector <long long> f(N);
set <long long> p;
vector <long long> pre;
void fibo(){
    long long f1 = 1, f2 = 1, f3;
    while (f1 + f2 <= n*2){
        long long f = f1 + f2;
        p.insert(f);
        f3 = f2;
        f2 = f;
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    fibo();
    cin >> n >> k;
    a.resize(n + 1);
    pre.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long sum = pre[j]-pre[i - 1];
            if (p.find(sum) != p.end()){
                d++;
            }
        }
    }
    cout << d;
    return 0;
}