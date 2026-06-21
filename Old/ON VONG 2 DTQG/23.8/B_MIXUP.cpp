#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> s;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    s.resize(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    long long ans = 0;
    do{
        bool check = true;
        for(int i = 0; i < n - 1; i++){
            if(abs(s[i] - s[i + 1]) <= k){
                check = false;
                break;
            }
        }
        if(check){
            ans++;
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}