#include <bits/stdc++.h>
using namespace std;
const long long MOD = 2023;
long long n;
vector<long long> a, b, c, d;
long long rmax = 0;
long long dem = 0;
vector<long long> ans;
bool check(long long i, long long j){
    long long li = min(a[i], c[i]);
    long long ri = max(b[i], d[i]);
    long long lj = min(a[j], c[j]);
    long long rj = max(b[j], d[j]);
    
    return !(ri < lj || rj < li);
}
bool check1(){
    for(long long i = 0; i < ans.size(); i++){
        for(long long j = i + 1; j < ans.size(); j++){
            if(check(ans[i], ans[j])){
                return false;
            }
        }
    }
    return true;
}
void xl(long long pos){
    if(pos == n + 1){
        if(check1()){
            long long k = ans.size();
            if(k > rmax){
                rmax = k;
                dem = 1;
            } else if(k == rmax){
                dem++;
            }
        }
        return;
    }  
    xl(pos + 1);
    ans.push_back(pos);
    xl(pos + 1);
    ans.pop_back();
}
void subtask1(){
    xl(1);
    cout << rmax << " " << dem % MOD;
}
#define task "HT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".INP", "r")){
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
    
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    c.resize(n + 1);
    d.resize(n + 1);
    for(long long i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    subtask1();
    return 0;
}