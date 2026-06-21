#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a, b;
long long lis (vector<long long> a){
    vector <long long> res;
    for (long long x : a){
        auto it = lower_bound(res.begin(), res.end(), x);
        if (it == res.end()){
            res.push_back(x);
        }
        else{
            *it = x;
        }
    }
    return res.size();
}
void subtask2(){ //k = 1;
    vector <long long> res;
    for (int i = 1; i <= n; i++){
        long long x = a[i];
        auto it = lower_bound(res.begin(), res.end(), x);
        if (it == res.end()){
            res.push_back(x);
        }
        else{
            *it = x;
        }
    }
    cout << res.size();
    // for (long long x : res){
    //     cerr << x << ' ';
    // }
}
void subtask1(){
    long long ans = 0;
    for (int i = 1; i <= k; i++){
        long long col = i;
        vector <long long> vt;
        // cerr << col <<'\n';
        for (int j = 1; j <= n; j++){
            if (b[j] == col){
                vt.push_back(a[j]);
            }
        }
        // for (long long x : vt){
        //     cerr << x << ' ';
        // }
        // cerr << '\n';
        long long res = lis(vt);
        ans = max(ans, res);
    }
    cout << ans;
}
#define task "daycon"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n + 5);
    b.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    // subtask2();
    // subtask1();
    if (k == 1){
        subtask2();
    }
    else{
        subtask1();
    }
    return 0;
}