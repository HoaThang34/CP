#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n;
vector<long long> a;
vector <long long> f(10, 0);
void subtask1(){
    long long p = 1;
    for(int i = 0; i < n; i++) p*=10;
    long long res = 0;
    for(int i = 1; i < p; i++){
        long long t = i;
        fill(f.begin(), f.end(), 0);
        while(t){
            f[t % 10]++;
            t /= 10;
        }
        bool check = true;
        for(int i = 0; i < 10; i++){
            if(f[i] < a[i]){
                check = false;
                break;
            }
        }
        if(check) res = (res + 1) % MOD;
    }
    cout << res;
}

#define task "ENCNUM"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(10);
    for(int i = 0; i <= 9; i++){
        cin >> a[i];
    }
    subtask1();
    return 0;
}