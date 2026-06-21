#include <bits/stdc++.h>
using namespace std;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long s = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    
    for(long long k = n; k >= 1; k--){
        if(k == 1){
            cout << 1 << endl;
            return 0;
        }
        
        if(s % k != 0) continue;
        
        long long t = s / k;
        long long sum = 0;
        long long cnt = 0;
        
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sum == t){
                cnt++;
                sum = 0;
                if(cnt == k) break;
            }
        }
        
        if(cnt == k && sum == 0){
            cout << k << endl;
            return 0;
        }
    }
    
    return 0;
}