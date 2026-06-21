#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
long long n, k;
vector <long long> a;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (long long i = 2; i * i <= N; i++){
        if (f[i]){
            for (long long j = i * i; j <= N; j += i){
                f[j] = false;
            }
        }
    }
}
void subtask1(){
    long long rmax = 0;
    set <long long> ans;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            long long d1 = 0, d2 = 0;
            for (int k = i; k <= j; k++){
                if (f[a[k]]){
                    d1++;
                }
                else{
                    d2++;
                }
            }
            if (d2 * k == d1){
                // cerr << d1 << ' ' << d2 << endl;
                long long len = j - i + 1;
                if (len > rmax){
                    rmax = len;
                    ans.clear();
                    ans.insert(i);
                }
                else if (len == rmax){
                    ans.insert(i);
                }
            }
        }
    }
    cout << rmax << endl;
    for (auto x : ans) cout << x << ' ';
}
void subtask2(){
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; i++){
        long long point = 0;
        if (f[a[i]]){
            point = 1;
        } else {
            point = -k;
        }
        pre[i] = pre[i - 1] + point;
    }
    map<long long, long long> pos;
    pos[0] = 0;
    long long rmax = 0;
    set<long long> ans;
    for (int i = 1; i <= n; i++){
        if (pos.count(pre[i])){
            long long j = pos[pre[i]];
            long long len = i - j;
            if (len > rmax){
                rmax = len;
                ans.clear();
                ans.insert(j + 1);
            }
            else if (len == rmax){
                ans.insert(j + 1);
            }
        } 
        else {
            pos[pre[i]] = i;
        }
    }
    cout << rmax << endl;
    for (long long x : ans){
        cout << x << " ";
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
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // subtask1();
    subtask2();
    return 0;
}