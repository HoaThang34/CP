#include <bits/stdc++.h>
using namespace std;
long long n, aa, cc;
vector<long long> a, c, x;
long long subtask1(long long i, long long val, long long w){
    if(i > n){
        return 0;
    }
    long long cnt1 = subtask1(i + 1, val, w);
    long long cnt2 = 0;
    for(long long p = 0; p <= c[i]; ++p){
        long long w1 = c[i] - p;
        long long w2 = p * x[i];
        if(val >= w1 && w >= w2){
            long long cur = a[i] + subtask1(i + 1, val - w1, w - w2);
            cnt2 = max(cnt2, cur);
        }
    }
    return max(cnt1, cnt2);
}
#define task "EXHIBITION"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> aa >> cc;
    a.resize(n + 1);
    c.resize(n + 1);
    x.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i] >> c[i] >> x[i];
    }
    cout << subtask1(1, aa, cc) << endl;
    return 0;
}