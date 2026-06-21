#include <bits/stdc++.h>
using namespace std;
long long n, t, a, b;
vector <long long> k;
void subtask1(){ //k giam dan
    long long ans = 0;
    long long time = t / a;
    if (time < n){
        for (int i = 1; i <= time; i++){
            ans = ans + k[i];
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            ans = ans + k[i];
        }
    }
    cout << ans;
}
void subtask2(){
    struct hoathang{
        long long val;
        long long cost;
    };
    vector<hoathang> v;
    for(int i=1;i<=n;i++){
        v.push_back({k[i],a}); 
        v.push_back({0,b}); 
    }
    sort(v.begin(),v.end(),[](hoathang x,hoathang y){
        return (long double)x.val/x.cost > (long double)y.val/y.cost;
    });
    long long ans=0, time=0;
    for(int i=0;i<v.size();i++){
        if(time+v[i].cost<=t){
            time+=v[i].cost;
            ans+=v[i].val;
        }
    }
    cout<<ans;
}

void subtask3(){ // k tang dan
    long long res = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        long long time = 0;
        long long ans = 0;
        for (int j = 1; j <= i; j++){
            time = time + b;
        }
        if (time <= t){
            long long curtime = t- time;
            long long lan = curtime/a;
            for (int j = i + 1; j <= i + lan; j++){
                if (j <= n){
                    ans = ans + k[j];
                }
            }
        }
        // cerr << ans << ' ';
        res = max(res, ans);
    }
    cout << res;
}
#define task "GAME"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> t >> a >> b;
    k.resize(n + 1);
    bool ok = true;
    bool ok1 = true;
    for (int i  = 1; i <= n; i++){
        cin >> k[i];
        if (i - 1 != 0){
            if (k[i - 1] < k[i]){
                ok = false;
            }
            else if (k[i - 1] > k[i]){
                ok1 = false;
            }
        }
    }
    // subtask1();
    // subtask2();
    // subtask3();
    if (ok){
        subtask1();
    }
    else if (ok1){
        subtask3();
    }
    else {
        subtask2();
    }
    return 0;
}