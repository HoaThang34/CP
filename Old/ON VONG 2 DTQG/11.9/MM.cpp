#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long n;
vector <long long> b;
void subtask1(){
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (b[i] > b[j]){
                long long k = b[i] % b[j];
                // cerr << k << ' ';
                ans = max(ans, k);
            }
        }
    }
    cout << ans;
}
void subtask2(){
    set <long long> st;
    for (long long x : b){
        st.insert(x);
    }
    long long ans = LLONG_MIN; 
    vector <long long> b;
    for (long long x : st){
        b.push_back(x);
    }
    long long rmax = b.back();
    for (long long x : b){
        if (x == 0) continue;
        for (long long i = x + x; i <= rmax + x; i+=x){
            auto it = upper_bound(b.begin(), b.end(), i - 1);
            if (it != b.begin()){
                long long v = *--it;
                if (v >= i - x){
                    ans = max(ans, v % x);
                }
            }
        }
    }
    cout << ans;
}
#define task "MM"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    // subtask1();
    // subtask2();
    if (n <= 1000){
        subtask1();       
    }
    else{
        subtask2();
    }
    return 0;
}
