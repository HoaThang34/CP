#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a, b;
#define task "TILLAGE"
long long xuli(vector<int> &f){
    long long res = LLONG_MAX;
    vector<int> arr = f;
    sort(arr.begin(), arr.end());
    do{
        long long cost = 0;
        for(int j = 0; j < (int)arr.size(); j++){
            int i = arr[j];
            cost += a[i] + 1LL * j * b[i];
        }
        res = min(res, cost);
    }while(next_permutation(arr.begin(), arr.end()));
    return res;
}
void subtask1(){
    for(int k = 1; k <= n; k++){
        long long ans = 0;
        vector<int> mask(n, 0);
        fill(mask.begin(), mask.begin() + k, 1);
        do{
            vector<int> sub;
            for(int i = 0; i < n; i++) if(mask[i]) sub.push_back(i);
            long long val = xuli(sub);
            ans = max(ans, val);
        }while(prev_permutation(mask.begin(), mask.end()));
        cout << ans << " ";
    }
    cout << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        b.resize(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        subtask1();
    }
    return 0;
}