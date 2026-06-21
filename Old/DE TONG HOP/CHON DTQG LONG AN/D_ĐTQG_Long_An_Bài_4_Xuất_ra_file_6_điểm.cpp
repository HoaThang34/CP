#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
void subtask1(){
    for(long long k = n; k >= 1; k--){
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= k){
                cnt++;
            }
        }
        if(cnt >= k){
            cout << k * k;
            return;
        }
    }
}
void subtask2(){
    sort(a.rbegin(), a.rend());
    long long rmax = 0;
    for(int i = 0; i < n; i++){
        long long rmin = min((long long)i + 1, a[i]);
        rmax = max(rmax, rmin);
    }
    cout << rmax * rmax;
}

#define task "GHEP"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    subtask2();
    return 0;
}