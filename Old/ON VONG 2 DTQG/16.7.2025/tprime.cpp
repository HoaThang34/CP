#include <bits/stdc++.h>
using namespace std;
long long n, k;
const long long N = 1e6 + 5;
vector <bool> f(N, true);
vector <long long> a;
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i < N; i++){
        if (f[i]){
            for (int j = i*i; j < N; j+=i){
                f[j] = false;
            }
        }
    }
}
long long xuli(long long n){
    if (f[n]){
        return 0;
    }
    else{
        long long i = n - 1, j = n + 1;
        while (i >= 2 || j < N){
            if (i >= 2 && f[i]){
                return abs(n - i);
            }
            if (j < N && f[j]){
                return abs(n - j);
            }
            i--;
            j++;
        }
    }
    return LLONG_MAX;
}
void subtask1(){
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) p[i] = xuli(a[i]);
    long long sum = 0;
    for (int i = 1; i <= k; i++) sum += p[i];
    long long rmin = sum;
    for (int i = k + 1; i <= n; i++){
        sum = sum - p[i - k] + p[i];
        rmin = min(rmin, sum);
    }
    cout << rmin;
}
#define task "tprime"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    sang();
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    subtask1();
    return 0;
}