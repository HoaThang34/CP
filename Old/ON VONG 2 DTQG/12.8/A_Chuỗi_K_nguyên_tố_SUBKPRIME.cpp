#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a;

const long long N = 1e6 +5;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; i++){
        if (f[i]){
            for (int j = i * i; j <= N; j+=i){
                f[j] = false;
            }
        }
    }
}
void subtask1(){
    set <int> ans;
    long long rmax = LLONG_MIN; 
    for (int i = 1; i <= n; i++){
        for (int j = i + k; j <= n; j++){
            long long d = 0, d1 = 0;
            for (int k1 = i; k1 <= j; k1++){
                if(f[a[k1]]){
                    d++;
                }
                else{
                    d1++;
                }
            }
            if (d == k * d1){
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
    for (int x : ans) cout << x << ' ';
}
void subtask2(){
    vector<long long> val(n+1,0), pref(n+1,0);
    for(int i=1;i<=n;i++){
        if(f[a[i]]) val[i] = k; 
        else val[i] = -1;
    }
    for(int i=1;i<=n;i++) pref[i] = pref[i-1] + val[i];
    unordered_map<long long,int> mp;
    mp.reserve(n*2);
    mp.max_load_factor(0.7);
    mp[0] = 0;
    long long rmax = 0;
    set<int> ans;
    for(int i=1;i<=n;i++){
        if(mp.find(pref[i]) != mp.end()){
            long long len = i - mp[pref[i]];
            if(len > rmax){
                rmax = len;
                ans.clear();
                ans.insert(mp[pref[i]] + 1);
            }
            else if(len == rmax){
                ans.insert(mp[pref[i]] + 1);
            }
        }
        else{
            mp[pref[i]] = i;
        }
    }
    cout << rmax << endl;
    for(int x : ans) cout << x << ' ';
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
    // if (n < 1000){
    //     subtask1;
    // }
    // else{
    //     subtask2();
    // }
    subtask2();
    return 0;
}