#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long rmax = LLONG_MIN;
vector <long long> a;
vector <bool> check;
bool checkcp(long long n){
    long long k = sqrt(n);
    return (k * k) == n; 
}
bool checklp(long long n){
    long long k = cbrt(n);
    return (k * k * k) == n;
}
void sang(){
    for (long long i = 1; i <= rmax; i++){
        if (checkcp(i) || checklp(i)){
            check[i] = true;
        }
    }
}
void subtask1(){
    check.resize(rmax + 1, false);
    sang();
    for (long long x : a){
        int d = 0;
        for (long long i = 1; i <= x; i++){
            if (check[i]) d++;
        }
        cout << d << endl;
    }
}
void subtask2(){
    for(long long x : a){
        long long scp = sqrt(x);
        long long slp = cbrt(x);
        long long scp_slp = sqrt(cbrt(x));
        cout << scp + slp - scp_slp << endl;
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> n;
        rmax = max(rmax, n);
        a.push_back(n);
    }    
    // subtask1();
    subtask2();
    return 0;
}