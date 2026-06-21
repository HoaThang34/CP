#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define task "proline"
long long n;
vector <long long> h;
set <long long> ans;
void subtask1(){
    for (int i = 1; i <= n; i++){
        vector <long long> b;
        b.push_back(h[i]);
        for (int j = i + 1; j <= n; j++){
            if (h[j] >= b[b.size() - 1] && h[j] != b[b.size() - 1]){
                b.push_back(h[j]);
            }
        }
        if (b.size() < 2){
            continue;
        }
        else{
            long long rmax = LLONG_MIN, rmin = LLONG_MAX;
            for (int j = 0; j < b.size(); j++){
                rmax = max(rmax, b[j]);
                rmin = min(rmin, b[j]);
            }
            long long k = rmax - rmin;
            for (int j = 1; j <= k; j++){
                for (int k = 0; k < b.size(); k++){
                    bool check = false;
                    long long s = b[k] + j;
                    for (int m = k; m < b.size(); m++){
                        if (b[m] == s){
                            check = true;
                            break;
                        }
                    }
                    if (check == true){
                        ans.insert(j);
                        break;
                    }
                }
            }
        }
    }
    cout << ans.size() % MOD;
}
void subtask2(){
    long long k;
    if (n % 2 == 0){
        k = n/2;
    }
    else{
        k = n/2 + 1;
    }
    long long sum = 1;
    for (long long i = 2; i <=n - 1; i++){
        if (i <= k){
            sum += (n / i + 1);
        }
        else sum += (n/i);
    }
    cout << sum;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    h.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    // subtask1();
    subtask2();
    return 0;
}