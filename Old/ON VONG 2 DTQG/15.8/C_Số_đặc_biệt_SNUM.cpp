#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long dg[20];
bool vst[20][163][1459][2];
long long f[20][163][1459][2];
long long gcd(long long a, long long b){
    long long tmp;
    while (b > 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
long long sum(long long n){
    long long s = 0;
    while (n > 0){
        s += (n % 10);
        n /= 10;
    }
    return s;
}
long long sumb(long long n){
    long long s = 0;
    while (n > 0){
        s += ((n % 10)*(n % 10));
        n /= 10;
    }
    return s;
}
bool check(long long n){
    long long s = sum(n);
    long long binh = sumb(n);
    if (gcd(s, binh) == 1){
        return true;
    }
    else return false;
}
void subtask1(){
    int d = 0;
    for (long long x = a; x <= b; x++){
        if (check(x)) d++;
    }
    cout << d;
}
long long dp(long long pos, long long s, long long ss, long long tight, long long l){
    if(pos == l){
        return gcd(s, ss) == 1;
    }
    if(vst[pos][s][ss][tight]){
        return f[pos][s][ss][tight];
    }
    vst[pos][s][ss][tight] = 1;
    long long &res = f[pos][s][ss][tight];
    res = 0;
    long long lim = tight ? dg[pos] : 9;
    for(int d = 0; d <= lim; d++){
        res += dp(pos + 1, s + d, ss + d * d, tight && (d == lim), l);
    }
    return res;
}
long long xuli(long long n){
    if(n < 0) return 0;
    long long l = 0;
    while(n){
        dg[l++] = n % 10;
        n /= 10;
    }
    if(l == 0) dg[l++] = 0;
    reverse(dg, dg + l);
    memset(vst, 0, sizeof(vst));
    return dp(0, 0, 0, 1, l);
}
void subtask2(){
    long long ans = xuli(b) - xuli(a - 1);
    cout << ans;
}
#define task "SNUM"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> a >> b;
    // subtask1();
    // subtask2();
    if (a <= 1000000 && b <= 1000000){
        subtask1();
    }
    else subtask2();
    return 0;
}