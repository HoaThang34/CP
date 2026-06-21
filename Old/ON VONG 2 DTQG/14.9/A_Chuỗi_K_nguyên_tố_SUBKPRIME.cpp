#include <bits/stdc++.h>
#include <climits>
using namespace std;
const long long N = 1e5+5;
long long n, k;
vector <long long> a;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; i++){
        if(f[i]){
            for (int j = i*i; j <= N; j+=i){
                f[j] = false;
            }
        }
    }
}
bool f1(long long x){
    if(!f[x] && x > 3){
        return true;
    }
    return false;
}
vector <long long> check1;
void sangsodep(){
    for (int i = 1; i <= n; i++){
        if (f[a[i]]){
            check1[i] = check1[i - 1] + 1;
        }
        else{
            check1[i] = check1[i - 1] + 0;
        }
    }
}
vector <long long> check2;
void sanghopso(){
    for (int i = 1; i <= n; i++){
        if (f1(a[i])){
            check2[i] = check2[i - 1] + 1;
        }
        else{
            check2[i] = check2[i - 1] + 0;
        }
    }
}
void subtask1(){
    sangsodep();
    sanghopso();
    vector <pair <long long, long long>> ans; // [len, pos]
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s1 = check1[j] - check1[i - 1]; //ngto
            long long s2 = check2[j] - check2[i - 1]; //hopso
            if (s2*k == s1){
                // cerr << i << ' ' << j << ' '  << s1 << ' ' << s2 << '\n';
                d = max(d, (long long)j - i + 1);
                ans.push_back({j - i + 1, i});
            }
        }
    }
    cout << d << '\n';
    for (pair<long long, long long> x : ans){
        if (x.first == d){
            cout << x.second << ' ';
        }
    }

}
void subtask2(){
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++){
        long long idk = 0;
        if (f[a[i]]){
            idk = 1;
        } else {
            idk = -k;
        }
        pre[i] = pre[i - 1] + idk;
    }
    map<long long, long long> pos1;
    long long rmax = 0;
    set<long long> pos2;
    for (int i = 0; i <= n; i++){
        if (pos1.count(pre[i])){
            long long j = pos1[pre[i]];
            long long clen = i - j;
            if (clen > rmax){
                rmax = clen;
                pos2.clear(); 
                pos2.insert(j + 1); 
            } else if (clen == rmax && clen > 0){
                pos2.insert(j + 1); 
            }
        } else {
            pos1[pre[i]] = i;
        }
    }
    cout << rmax << '\n';
    for (long long x : pos2){
        cout << x << ' ';
    }
}
#define task "SUBKPRIME"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    sang();
    cin >> n >> k;
    a.resize(n + 5);
    check1.resize(n + 5, 0);
    check2.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }    
    // subtask1();
    subtask2();
    return 0;
}