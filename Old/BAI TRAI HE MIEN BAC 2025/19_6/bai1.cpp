#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long ghep(long long a, long long b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    string res = s1 + s2;
    long long res1 = stoll(res);
    return res1;
}
vector <long long> a, b;
void subtask1(){
    int d = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            long long res = ghep(a[i], b[j]);
            if (res % k == 0) d++;
        }
    }
    cout << d;
}
void subtask2(){
    long long ml = 0;
    for(long long i = 0; i < n; i++){
        long long len = b[i] == 0 ? 1:(long long)to_string(b[i]).length();
        if(len > ml) ml = len;
    }
    vector<vector<long long>> c(ml + 1, vector<long long>(k, 0));
    for(long long i = 0; i < n; i++){
        long long len = b[i] == 0 ? 1:(long long)to_string(b[i]).length();
        c[len][b[i]%k]++;
    }
    vector<long long>p(ml+1);
    p[0] = 1%k;
    for(long long i = 1; i <= ml;i++) p[i]=(p[i-1]*10)%k;
    long long res=0;
    for(long long i = 0; i < n; i++){
        long long ra = a[i] % k;
        for(long long len = 1;len <= ml; len++){
            long long nr = (k - (ra*p[len])%k)%k;
            res += c[len][nr];
        }
    }
    cout << res;
}
#define task "KDIVI"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // subtask1();
    subtask2();
    return 0;
}