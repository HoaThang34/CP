#include <bits/stdc++.h>
using namespace std;
#define task "CUTSEQ"
long long n;
string s;
long long a[205];
long long solve(long long l,long long r,long long k){
    if(l > r) return 0;
    long long rr = r, kk = k;
    while(l < rr && a[rr] == a[rr-1]){
        kk++;
        rr--;
    }
    if(rr != r) return solve(l, rr, kk);
    long long res = solve(l, r-1, 0) + (kk+1)*(kk+1);
    for(int i = l; i < r; i++){
        if(a[i] == a[r]){
            res = max(res, solve(l, i, kk+1) + solve(i+1, r-1, 0));
        }
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
    cout << solve(1, n, 0);
}
