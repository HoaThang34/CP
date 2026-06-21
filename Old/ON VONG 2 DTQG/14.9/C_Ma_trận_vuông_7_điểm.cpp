#include <bits/stdc++.h>
using namespace std;
long long n, x;
vector <long long> a;
vector<long long> f;
void subtask1(){
    int d = 0;
    for (long long k = 1; k <= n; k++){
        for (long long i = 1; i <= n - k + 1; i++){
            for (long long j = 1; j <= n - k + 1; j++){
                long long s1 = f[i + k - 1] - f[i - 1];
                long long s2 = f[j + k - 1] - f[j - 1];
                if (k * (s1 + s2) == x){
                    d++;
                }
            }
        }
    }
    cout << d << '\n';
}
void subtask2(){
    long long ans = 0;
    for(long long k = 1; k <= n; k++){
        if(x % k != 0) continue;
        long long idk = x / k;
        vector<long long> sum;
        for(int i = 1; i <= n - k + 1; i++){
            sum.push_back(f[i + k - 1] - f[i - 1]);
        }
        map<long long, long long> dem;
        for(int j = 1; j <= n - k + 1; j++){
            dem[f[j + k - 1] - f[j - 1]]++;
        }
        for(long long x : sum){
            long long d = idk - x;
            if(dem.count(d)){
                ans += dem[d];
            }
        }
    }
    cout << ans << '\n';
}
void subtask3(){ 
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            long long l = 1, r = n - max(i, j) + 1;
            while(l <= r){
                long long k = l + (r - l) / 2;
                if(k == 0){
                    l = k + 1;
                    continue;
                }
                long long s1 = f[i + k - 1] - f[i - 1];
                long long s2 = f[j + k - 1] - f[j - 1];
                long long idk = x / k;
                if (s1 > idk - s2){ // lon hon
                    r = k - 1;
                } else if (s1 < idk - s2){ // nho hon
                    l = k + 1;
                } else{
                    if (x % k == 0){
                        ans++;
                    }
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}
void subtask4(){
    long long ans = 0;
    for (long long k = 1; k <= n; k++){
        if (x % k != 0){
            continue;
        }
        long long idk = x / k;
        map<long long, long long> mp;
        for (long long i = 1; i <= n - k + 1; i++){
            long long s = f[i + k - 1] - f[i - 1];
            mp[s]++;
        }
        for (long long i = 1; i <= n - k + 1; i++){
            long long s = f[i + k - 1] - f[i - 1];
            long long dis = idk - s;
            if (mp.count(dis)){
                ans += mp[dis];
            }
        }
    }
    cout << ans << '\n';
}

void solve(){
    cin >> n >> x;
    a.assign(n + 1, 0);
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    // subtask1();
    // subtask2();
    // subtask3();
    subtask4();
}
#define task "SQMATRIX"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}