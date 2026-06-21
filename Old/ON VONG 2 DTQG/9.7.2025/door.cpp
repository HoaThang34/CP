#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, s;
vector <long long> a;
long long f[45][10005];
void subtask1(){
    f[0][0] = 1;
    for (long long i = 1; i <= n; i++){
        for (long long j = 0; j <= s; j++){
            f[i][j] = f[i - 1][j];
            if (j >= a[i]){
                f[i][j] += f[i-1][j-a[i]];
            }
        }
    }
    cout << f[n][s] % MOD;
}
void gen(int i, int h, long long sm, vector<long long>& v){
    if(i > h){
        v.push_back(sm);
        return;
    }
    gen(i+1, h, sm, v);
    gen(i+1, h, sm+a[i], v);
}
void subtask2(){
    int m = n / 2;
    vector<long long> l, r;
    gen(1, m, 0, l);
    gen(m+1, n, 0, r);
    sort(l.begin(), l.end());
    long long res = 0;
    for(long long x : r){
        long long t = s - x;
        auto p = equal_range(l.begin(), l.end(), t);
        res += p.second - p.first;
    }
    cout << res % MOD;
}
#define task "door"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> s;
    a.resize(n + 1);
    for (long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    // if (n <= 20){
    //     subtask1();
    // }
    // else subtask2();
    subtask2();
    return 0;
}
